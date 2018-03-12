#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1100

long long mapa[lim][lim] ;
long long bit[lim][lim] ;

void mete( int R, int C, long long nov ) {	
	for( int i=R; i<lim; i+=(i & -i)  ) 
		for( int j=C; j<lim; j+=( j & -j )   ) 
			bit[i][j] += nov ;	
}

long long carga( int R, int C ) {
	long long res = 0LL ;
	for( int i=R; i>0; i -= (i & -i)   )
		for( int j=C; j>0; j -= (j & -j)   )
			res += bit[i][j] ;
	return res ;
}

void caso() {
	char S[5] ;
	int a, b, c, d ;
	long long x ;
	
	scanf("%d", &a ) ;
	for( int i=0; i<lim; i++ ) {
		for( int j=0; j<lim; j++ ) {
			mapa[i][j] = 0LL ;
			bit[i][j] = 0LL ;
		}
	}
	
	
	do {
		scanf("%s", S ) ;
		if( S[1] == 'U' ) {
			scanf("%d%d%d%d", &a, &b, &c, &d ) ;
			printf("%lld\n", carga(c+1,d+1) - carga(a,b) ) ;
		}
		else if( S[1] == 'E' ) {
			scanf("%d%d%lld", &a, &b, &x ) ;	
			a ++ ;
			b ++ ;
			mete( a, b, x-mapa[a][b] ) ;
			mapa[a][b] = x ;
		}
	} while( S[0] != 'E' ) ;
}

int main() {
	int T ;
	
	for( scanf("%d", &T); T; T-- ) 
		caso() ;
	
	return 0 ;
}
