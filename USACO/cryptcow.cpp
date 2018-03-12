/*
ID: chencho2
LANG: C++
TASK: cryptcow
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 200
#define num 22LL
#define mod 99999999977LL

int N, O ;
int sig[lim], ant[lim] ;
char S[lim] ;
char org[] = "Begin the Escape execution at the Break of Dawn" ;
char cpy[] = "Begin the Escape execution at the Break of Dawn" ;

bool subseg( short int pos, short int posIni, short int posFin, short int ini, short int fin ) {
	if( ini>fin )
		return 1 ;
	
	short int T = 0 ;
	short int i, j ;
	
	while( S[pos]!='C' && S[pos]!='O' && S[pos]!='W'   &&  pos!=posIni   )
		pos = ant[pos] ;
	if( S[pos]=='C' || S[pos]=='O' || S[pos]=='W'  )
		pos = sig[pos] ;
	while( S[pos]!='C' && S[pos]!='O' && S[pos]!='W'   &&  pos!=posFin   )  {
		cpy[T++] = S[pos] ;
		pos = sig[pos] ;
	}
	if( S[pos]!='C' && S[pos]!='O' && S[pos]!='W'  )
		cpy[T++] = S[pos] ;
	if( T>fin-ini+1  )
		return 1 ;
		
	for( i=ini; i+T-1<=fin; i++  ) {
		for( j=0; j<T && cpy[j]==org[i+j]; j++  ) ; 
		if( j==T )
			return 1 ;
	}
	
	return 0 ;
}

bool parte( short int posIni, short int posFin, short int ini, short int fin ) {	
	if( ini>fin )
		return 1 ;
	// Revisar que las orillas sean iguales
	for( ; ini<=fin && S[posIni]==org[ini];  ini++, posIni=sig[posIni]   )   ;
	if( ini>fin  )
		return 1 ;
	if( S[posIni] != 'C'  )
		return 0 ;
	for( ; S[posFin]==org[fin];  fin--, posFin=ant[posFin]   )  ;
	if( S[posFin] != 'W'  )
		return 0 ;
		
	/*for( short int oeuidht=posIni; oeuidht!=posFin; oeuidht=sig[oeuidht] ) {
		printf("%c", S[oeuidht] ) ;
	}
	printf("%c", S[posFin] ) ;
	cout << endl ;
	getchar() ;*/

	// Revisar que el texto que sigue a las orillas este antes o despues de 
	// una 'O'
    short int pos, i, w=0 ;
    pos = posIni ;
    while( pos!=posFin  )   {
        if(  S[pos] == 'C' ||  S[pos] == 'W'   ) {
            pos = sig[pos] ;
            while( S[pos] != 'C' &&  S[pos] != 'O' &&   S[pos] != 'W'   )
                pos = sig[pos] ;
            continue ;
        }
        pos = sig[pos] ;
        i = ini ;
        while( S[pos] == org[i]   )   {
            pos = sig[pos] ;
            i ++ ;
        }
        if(  S[pos] == 'C' ||  S[pos] == 'O' ||   S[pos] == 'W'  ) {
			w = 1 ;
            break ;
		}
        while( S[pos] != 'C' &&  S[pos] != 'O' &&   S[pos] != 'W'   )
            pos = sig[pos] ;
    }
    if( !w  )
        return 0 ;

    pos = posFin ;
    while( pos!=posIni  )   {
        if(  S[pos] == 'C' ||  S[pos] == 'W'  ) {
            pos = ant[pos] ;
            while( S[pos] != 'C' &&  S[pos] != 'O' &&   S[pos] != 'W'   )
                pos = ant[pos] ;
            continue ;
        }
        pos = ant[pos] ;
        i = fin ;
        while( S[pos] == org[i]   )   {
            pos = ant[pos] ;
            i -- ;
        }
        if(  S[pos] == 'C' ||  S[pos] == 'O' ||   S[pos] == 'W'  ) {
			w = 1 ;
            break ;
		}
        while( S[pos] != 'C' &&  S[pos] != 'O' &&   S[pos] != 'W'   )
            pos = ant[pos] ;
    }
    if( !w  )
        return 0 ;
        
	// Guardar todas las pocisiones de C, O y Ws 
	short int C=0 ;
	char check[35] ;
	char tip[35] ;
	short int j, k, a, b ;
	short int x, y, z ;
	short int pnt ;
	pos = posIni ;
	while( pos!=posFin  )   {		
		//printf("%c", S[pos] ) ;
		check[C] = pos ;
		tip[C] = S[pos] ;
		C ++ ;
        pos = sig[pos] ;
		while( S[pos] != 'C' &&  S[pos] != 'O' &&   S[pos] != 'W'   )
			pos = sig[pos] ;
    }
    check[C] = pos ;
	tip[C] = S[pos] ;
	C ++ ;
	
	/*for( i=0; i<C; i++ ) 
		printf("%2d ", check[i] ) ;
	cout << endl ;
	for( i=0; i<C; i++ ) 
		printf(" %c ", tip[i] ) ;
	cout << endl ;*/
    // Probar todas las combinaciones hasta que haya una buena
    for( i=0; i<C; i++ ) {
		if( tip[i] != 'C' )
			continue ;
		for( j=i+1; j<C; j++  )   {
			if( tip[j] != 'O' )
				continue ;
			for( k=j+1; k<C; k++ ) {
				if( tip[k] != 'W' )
					continue ;
				
				x = check[i] ;
				y = check[j] ;
				z = check[k] ;
				a = posIni ;
				b = posFin ;
				
				/*cout << i << " " << j << " " << k << endl ;
				cout << x << " " << y << " " << z << endl ;
				cout << tip[i] << tip[j] << tip[k] << endl ;*/
				
				if( sig[x] == y && sig[y] == z  )  {
					//cout << "ouhnhsh" << endl ;
					if( a==x )
						a = sig[z] ;
					if( b==z )
						b = ant[x] ;
					sig[ ant[x] ] = sig[z] ;
					ant[ sig[z] ] = ant[x] ;
					pnt = subseg( ant[x], a, b, ini, fin ) ;
				}
				else if( sig[x] == y  )  {
					//cout << "'qjkx" << endl ;
					if( a==x )
						a = sig[y] ;
					if( b==z )
						b = ant[z] ;
					sig[ ant[x] ] = sig[y] ;
					sig[ ant[z] ] = sig[z] ;
					ant[ sig[y] ] = ant[x] ;
					ant[ sig[z] ] = ant[z] ;
					pnt = subseg( sig[y], a, b, ini, fin ) && subseg( ant[z], a, b, ini, fin ) ;
				}
				else if( sig[y] == z ) {
					//cout << ";,.ppp" << endl ;
					if( a==x )
						a = sig[x] ;
					if( b==z )
						b = ant[y] ;
					sig[ ant[x] ] = sig[x] ;
					sig[ ant[y] ] = sig[z] ;
					ant[ sig[x] ] = ant[x] ;
					ant[ sig[z] ] = ant[y] ;
					pnt = subseg( sig[x], a, b, ini, fin ) && subseg( ant[y], a, b, ini, fin ) ;
				}
				else {				
					//cout << "crl/" << endl ;
					a = posIni ;
					b = posFin ;
					if( a==x ) 
						a = sig[ y ] ;
					if( b==z )
						b = ant[ y ] ;		
					sig[ ant[x] ] = sig[y] ;
					sig[ ant[y] ] = sig[z] ;				
					sig[ ant[z] ] = sig[x] ;					
					ant[ sig[y] ] = ant[x] ;
					ant[ sig[z] ] = ant[y] ;
					ant[ sig[x] ] = ant[z] ;
					pnt = subseg( sig[y], a, b, ini, fin ) && subseg( ant[z], a, b, ini, fin ) && subseg( ant[y], a, b, ini, fin ) ;
				}
				/*cout << x << " " << y << " " << z << endl ;				
				cout << a << " " << b << endl ;
				for( short int quajuathsts=a; quajuathsts!=b; quajuathsts=sig[quajuathsts] ) {
					printf("%c", S[quajuathsts] ) ;
				}
				printf("%c\n", S[b] ) ;
				for( short int quajuathsts=b; quajuathsts!=a; quajuathsts=ant[quajuathsts] ) {
					printf("%c", S[quajuathsts] ) ;
				}
				printf("%c\n", S[a] ) ;
				getchar() ;*/
				if( pnt  &&  parte( a, b, ini, fin ) )
					return 1 ;
				sig[ ant[x] ] = x ;
				sig[ ant[y] ] = y ;
				sig[ ant[z] ] = z ;
				ant[ sig[x] ] = x ;
				ant[ sig[y] ] = y ;
				ant[ sig[z] ] = z ;
				/*for( short int pos=posIni; pos!=posFin; pos=sig[pos] ) {
					printf("%c", S[pos] ) ;
				}
				printf("%c", S[posFin] ) ;
				cout << endl ;
				getchar() ;*/
			}
		}
	}

	return 0 ;
}

bool repet() {	
	short int A=0, B=0, C=0 ;
	short int posa[22], posb[22], posc[22] ;
	short int rep[256], rep2[256] ;
	memset( rep, 0, sizeof(rep)  ) ;
	memset( rep2, 0, sizeof(rep2)  ) ;
	for( short int i=0; i<N; i++ ) {
		if( S[i]=='C'  )
			posa[A++] = i ;
		else if( S[i]=='O'  )
			posb[B++] = i ;
		else if( S[i]=='W'  )
			posc[C++] = i ;
		else
			rep[ S[i] ] ++ ;
	}
	for( short int i=0; i<O; i++ )
		rep2[ org[i] ] ++ ;
	for( short int i=0; i<256; i++ ) {
		if( rep[i] != rep2[i] )
			return 0 ;
	}
	return A==B && B==C ;
}

void simpf() {
	sort( cpy, cpy+O ) ;
	for( short int i=0, w=0; i<O; i++ ) {
		if( i && cpy[i]==cpy[i-1]  )
			continue ;
		for( short int j=0; j<N; j++ ) {
			if( cpy[i] == S[j]  )
				S[j] = w ;
		}
		for( short int j=0; j<O; j++ ) {
			if( cpy[i] == org[j]  )
				org[j] = w ;
		}
		w ++ ;
	}
	for( short int i=0; i<N; i++ ) {
		if( S[i]<' '  )
			S[i] += 'a' ;
	}
	for( short int i=0; i<O; i++ )
		if( org[i]<' '  )
			org[i] += 'a' ;
}


int main() {
	//freopen( "ent.in", "r", stdin ) ;
	freopen( "cryptcow.in", "r", stdin ) ;
	freopen( "cryptcow.out", "w", stdout ) ;

	gets( S ) ;

	N = strlen( S ) ;
	O = strlen( org ) ;
	for( int i=0; i<N; i++ ) {
		sig[i] = i+1 ;
		ant[i] = i-1 ;
	}
	sig[N-1] = 100 ;
	ant[0] = 100 ;
	S[100] = 'Q' ;
	simpf() ;

	if( repet() && parte(0,N-1,0,O-1) )
		printf("1 %d\n", (N-O)/3  ) ;
	else
		printf("0 0\n" ) ;

	return 0 ;
}
