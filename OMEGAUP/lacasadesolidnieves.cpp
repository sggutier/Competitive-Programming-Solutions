#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 503 ;
const int limK = 8003 ;

int N, E, K ;
int minP[lim][lim] ;
int imp[limK] ;

int main() {
    int res=(1<<30), pRes ;

    scanf("%d%d%d", &N, &K, &E ) ;
    for( int i=0; i<K; i++ )
        scanf("%d", &imp[i] ) ;
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<N; j++ )
            minP[i][j] = (1<<29) ;
        minP[i][i] = 0 ;
    }
    for( int i=0; i<E; i++ ) {
        int a, b, c ;
        scanf("%d%d%d", &a, &b, &c ) ;
        a--, b-- ;
        minP[a][b] = c ;
        minP[b][a] = c ;
    }

    for( int k=0; k<N; k++ ) {
        for( int i=0; i<N; i++ ) {
            for( int j=0; j<N; j++ ) {
                minP[i][j] = min( minP[i][j], minP[i][k]+ minP[j][k] ) ;
            }
        }
    }

    for( int i=0; i<N; i++ ) {
        int tmp = 0 ;
        for( int j=0; j<K; j++ ) {
            tmp += minP[i][ imp[j]-1 ] ;
        }
        if( tmp<res ) {
            res = tmp ;
            pRes = i ;
        }
    }

    printf("%d\n", pRes+1 ) ;

    return 0 ;
}
