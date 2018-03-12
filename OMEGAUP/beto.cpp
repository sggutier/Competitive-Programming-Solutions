#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <list>
#include <utility>
#include <cstring>
#include <vector>
using namespace std ;
#define par pair<short,int>
#define f first
#define s second
#define lim 15

int N, E ;
vector <par> adj[lim] ;
int minP[lim][2] ;
int B[lim] ;

int main() {
    int nA, nB ;
    int res = (1<<30) ;
    int act=0, sig=1 ;

    scanf("%d%d", &N, &E ) ;
    scanf("%d%d", &nA, &nB ) ;
    for( int i=0; i<N; i++ )
        minP[i][act] = (1<<30) ;
    for( int i=0; i<nA; i++ )  {
        int K ;
        scanf("%d", &K ) ;
        minP[K][act] = 0 ;
    }
    for( int i=0; i<nB; i++ )
        scanf("%d", &B[i] ) ;
    for( int i=0; i<E; i++ ) {
        int a, b, c ;
        scanf("%d%d%d", &a, &b, &c ) ;
        //adj[a].push_back( par(c,b) ) ;
        //adj[b].push_back( par(c,a) ) ;
    }

    for( int W=N; W; W-- ) {
        for( int i=0; i<N; i++ )
            minP[i][sig] = minP[i][act] ;
        for( int i=0; i<N; i++ )
            //for( list<par>::iterator it=adj[i].begin(); it!=adj[i].end(); it++ )
                //minP[it->s][sig] = min( minP[it->s][sig], minP[i][act] + (it->f) ) ;
            for( int j=0; j<adj[i].size(); j++ )
                minP[adj[i][j].s][sig] = min( minP[adj[i][j].s][sig], minP[i][act] + adj[i][j].f ) ;
        swap( sig, act ) ;
    }

    for( int i=0; i<nB; i++ )
        res = min( res, minP[B[i]][act] ) ;

    printf("%d\n", res ) ;

    return 0 ;
}
