#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#include <list>
using namespace std ;
#define lim 20

int N, E ;
list <int> adj[lim] ;
int minP[lim][1<<lim] ;
queue <int> Q ;

int main() {
    int res = (1<<30) ;

    scanf("%d%d", &N, &E ) ;
    for( int i=0; i<E; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        a--, b-- ;
        adj[a].push_back(b) ;
    }

    minP[0][1] = 0 ;
    Q.push(1) ;
    while( !Q.empty() ) {
        int pos, masc, a, b ;
        pos = Q.front() ;
        masc = pos%(1<<lim) ;
        pos /= (1<<lim) ;
        Q.pop() ;

        for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
            a = *it ;
            b = masc | (1<<(*it)) ;
            if( minP[a][b] )
                continue ;
            minP[a][b] = minP[pos][masc]+1 ;
            Q.push( a*(1<<lim) + b ) ;
        }
    }

    for( int i=0; i<(1<<(N-2)); i++ ) {
        if( !minP[0][ 3 + (i<<2) ] )
            continue ;
        int tmp = 0 ;
        for( int b=0; b<N; b++ ) {
            if( (1<<b) & i)
                tmp ++ ;
        }
        res = min( res, tmp+2  ) ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
