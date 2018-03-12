#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std ;
const int lim = 205 ;

int N, M ;
stack <int> carg[lim][lim] ;

int main() {
    int K ;
    int G, C ;

    scanf("%d%d", &M, &N ) ;
    scanf("%d%d", &G, &C ) ;
    for( int k=0; k<G; k++ ) {
        for( int i=0; i<N; i++ )
            for( int j=0; j<M; j++ )
                carg[i][j].push(C) ;
    }

    scanf("%d", &K ) ;
    for( int w=0; w<K; w++ ) {
        int x, y, r, c ;
        scanf("%d", &C ) ;
        scanf("%d%d%d%d", &y, &x, &c, &r ) ;
        r--, c-- ;
        if( C==-1 ) {
            for( int i=0; i<x; i++ )
                for( int j=0; j<y; j++ )
                    if( !carg[i+r][j+c].empty() )
                        carg[i+r][j+c].pop() ;
        }
        else {
            for( int i=0; i<x; i++ )
                for( int j=0; j<y; j++ )
                    carg[i+r][j+c].push( C ) ;
        }
    }

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ )
            if( carg[i][j].empty() )
                printf("-1 " ) ;
            else
                printf("%d ", carg[i][j].top() ) ;
        printf("\n" ) ;
    }

    return 0 ;
}
