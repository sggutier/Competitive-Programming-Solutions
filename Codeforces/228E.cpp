#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std ;
const int limN = 100 ;
const int limN2 = limN*2 ;
const int limE = limN*limN + 5 ;
const int inf = (1<<30) ;

int N, W=1 ;
bool adj[limN2][limN2] ;
int minId[limN2] ;
bool usd[limN] ;
stack <int> Q ;

int tarjan( int pos ) {
    if( minId[pos] )
        return minId[pos] ;

    minId[pos] = W ;
    int K = W ;
    W ++ ;
    Q.push(pos) ;

    for( int i=0; i<N; i++ ) {
        if( adj[pos][i] )
            minId[pos] = min( minId[pos], tarjan(i) ) ;
        if( adj[pos][i+limN] )
            minId[pos] = min( minId[pos], tarjan(i+limN) ) ;
    }

    if( K==minId[pos] ) {
        int T = 0 ;
        int arr[limN2] ;

        do {
            arr[T++] = Q.top() ;
            Q.pop() ;
        } while( arr[T-1]!=pos ) ;

        for( int i=0; i<T; i++ ) {
            minId[ arr[i] ] = inf ;
            for( int j=0; j<T; j++ )
                adj[ arr[i] ][ arr[j] ] = 1 ;
        }
    }

    return minId[pos] ;
}

int main() {
    int E, R=0 ;
    int res[limN] ;

    scanf("%d%d", &N, &E ) ;
    for( int i=0; i<E; i++ ) {
        int a, b, c ;
        scanf("%d%d%d", &a, &b, &c ) ;
        a--, b-- ;
        if( c ) {
            adj[a][b] = 1 ;
            adj[b][a] = 1 ;
            adj[ a+limN ][ b+limN ] = 1 ;
            adj[ b+limN ][ a+limN ] = 1 ;
        }
        else {
            adj[a][ b+limN ] = 1 ;
            adj[ b+limN ][a] = 1 ;
            adj[ b ][ a+limN ] = 1 ;
            adj[ a+limN ][ b ] = 1 ;
        }
    }

    for( int i=0; i<N; i++ ) {
        tarjan(i) ;
        tarjan( i+limN ) ;
        if( adj[i][i+limN] ) {
            printf("Impossible\n" ) ;
            return 0 ;
        }
    }

    for( int i=0; i<N; i++ ) {
        if( usd[i] )
            continue ;
        adj[i][i] = 1 ;
        for( int j=0; j<limN2; j++ ) {
            if( adj[i][j] ) {
                if( j>=limN )
                    res[R++] = j-limN ;
                usd[j%limN] = 1 ;
            }
        }
    }

    printf("%d\n", R ) ;
    for( int i=0; i<R; i++ )
        printf("%d ", res[i]+1 ) ;
    printf("\n" ) ;

    return 0 ;
}
