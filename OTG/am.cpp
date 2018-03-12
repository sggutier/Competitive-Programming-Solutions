#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
using namespace std ;
#define lim 100007

int padre[lim] ;
int rang[lim] ;

int raiz( int pos ) {
	if( padre[pos] == pos ) {
		return pos ;
	}
	padre[pos] = raiz( padre[pos] ) ;
	return padre[pos] ;
}

void une( int a, int b, bool p  ) {
	a = raiz( a ), b = raiz( b ) ;
	if( a == b ) {
		return ;
	}
	
	if( rang[a] > rang[b]  )  {
		padre[b] = a ;
	} 
	else if( rang[a] < rang[b] ) {
		padre[a] = b ;
	}
	else {
		padre[a] = b ;
		rang[b] ++ ;
	}
}

int main() {
	int N, E ;
	char S[6] ;
	int a, b, i ;
	
	for( i=0; i<lim; i++ ) {
		padre[i] = i ;
		rang[i] = 0 ;
	}
	
	scanf("%d%d", &N, &E ) ;
	while( E ) {
		E -- ;
		scanf("%s", S ) ;
		scanf("%d%d", &a,&b) ;
		if( S[0] == 'S' ) {
			une( a, b ) ;
		}
		else {
			printf("%d\n", raiz(a) == raiz(b) ) ;
		}
	}
	
	return 0 ;
}
