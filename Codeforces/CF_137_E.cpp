#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define inf (1<<30)
#define lim 400005

//Se usa un BIT para guardar los menores valores de las sumas hasta el
//momento
//Todo se inicializa en inf 
int N ;
char S[lim] ;
int bit[lim*2] ;

bool vocal( char a ) ;
void meteBit( int pos, int nov ) ;
int pregBit( int pos ) ;

int main() {
	int carg = 0 ;
	int maxTam = -1, numMaxTam = 0 ;
	
	//Leer e inicializar
	scanf("%s", S ) ;
	N = strlen( S ) ;
	for( int i=lim*2-1; i>=0; i-- ) 
		bit[i] = inf ;
	
	//Para cada elemento se suma el elemento a la carga
	//Luego se busca la pocision mas pequenia que lo complemente con el
	//BIT
	meteBit( lim, -1 ) ;
	for( int i=0; i<N; i++ ) {
		int w ;
		if( !vocal(S[i])   ) 
			carg += 2 ;
		else
			carg -- ;
		w = i - pregBit( lim+carg  ) ;
		meteBit(carg+lim,i) ;
		
		if( w>maxTam ) {
			maxTam = w ;
			numMaxTam = 1 ;
		}
		else if( w==maxTam ) {
			numMaxTam ++ ;
		}
	}
	
	if( maxTam!=-1 )
		printf("%d %d\n", maxTam, numMaxTam ) ;
	else
		printf("No solution\n" ) ;
	
	return 0 ;
}

bool vocal( char a ) {
	return a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U' ; 
}

void meteBit( int pos, int nov ) {
	int N = lim*2 ;
	for( ; pos<N; pos += (pos & -pos)   )
		bit[pos] = min( bit[pos], nov ) ;
}

int pregBit( int pos ) {
	int res = inf ;
	for( ; pos; pos -= (pos & -pos)   )
		res = min( res, bit[pos]  ) ;
	return res ;
}
