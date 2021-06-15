#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 1035 ;

int tam[lim] ;
int res[lim][lim] ;
bool adj[lim][lim] ;
bool usd[lim] ;

int main() {
	//freopen(  "input.txt", "r", stdin   ) ;
	//freopen( "output.txt", "w", stdout  ) ;

	int N, W, R=0, N2 ;
	int K ;

	scanf("%d", &N ) ;

	N2 = 1 ;
	while( N2<N )
        N2 *= 2 ;
    swap( N, N2 ) ;

	W = N/2 + N%2 ;
	K = N*(N-1) ;

	while( K ) {
		memset( usd, 0, sizeof(usd) ) ;
		for( int i=0; i<N; i++ ) {
			if( tam[R]<W ) {
				if( usd[i] )
					continue ;
				if( adj[i][i+1]  ) {
					usd[i] = 1 ;
					continue ;
				}
				int j = N-1 ;
				while( adj[i][j] || usd[j] )
					j -- ;
				res[R][ tam[R]++ ] = i ;
				//cout << i+1 << " " ;
				if( j==i )
					continue ;
				usd[j] = 1 ;
			}
			else {
				usd[i] = 1 ;
			}
		}
		//cout << endl ;
		for( int i=0; i<N; i++ ) {
			if( !usd[i] ) {
				for( int j=i+1; j<N; j++ ) {
					if( !adj[i][j] && usd[j] ) {
						adj[i][j] = 1 ;
						K -= 2 ;
					}
				}
			}
		}
		R ++ ;
	}

	printf("%d\n", R ) ;
	for( int i=0; i<R; i++ ) {
	    int tmp = 0 ;
	    for( int j=0; j<tam[i]; j++ )
            if( res[i][j]+1<N2 )
                tmp ++ ;
		printf("%d", tmp ) ;
		for( int j=0; j<tam[i]; j++ )
            if( res[i][j]+1<N2 )
                printf(" %d", res[i][j]+1 ) ;
		printf("\n" ) ;
	}

	return 0 ;
}
