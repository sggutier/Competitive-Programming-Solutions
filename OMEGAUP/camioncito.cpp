#include <cstdio>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second
const int lim = 1003 ;
const int limK = 15 ;

int N, E, K ;
list <par> adj[lim] ;
priority_queue <par> Q ;
int minP[lim][lim] ;
bool usd[lim][lim] ;
int imp[limK] ;

void dijkstra( int ini ) {
    Q.push( par(-1,ini) ) ;
    minP[ini][ini] = 1 ;

    while( !Q.empty() ) {
        par tmp = Q.top() ;
        int pos=tmp.s, crg=tmp.f ;
        Q.pop() ;
        if( usd[ini][pos] )
            continue ;
        usd[ini][pos] = 1 ;
        //cout << ini+1 << " " << pos+1 << " " << minP[ini][pos]-1 << endl ;

        for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
            if( !minP[ini][it->s] || minP[ini][it->s]>-crg+it->f ) {
                Q.push( par( crg - it->f, it->s)  ) ;
                minP[ini][it->s] = -crg + it->f ;
            }
        }
    }
}

int main() {
    int ini, fin ;
    int res = (1<<30) ;

    scanf("%d%d%d", &K, &E, &N) ;
    scanf("%d%d", &ini, &fin ) ;
    for( int i=0; i<E; i++ ) {
        int a, b, c ;
        scanf("%d%d%d", &a, &b, &c ) ;
        a--, b-- ;
        adj[a].push_back (par( c, b )) ;
        adj[b].push_back (par( c, a )) ;
    }

    ini--, fin-- ;
    imp[0] = ini ;
    for( int i=1; i<=K; i++ ) {
        scanf("%d", &imp[i] ) ;
        imp[i]-- ;
    }
    imp[K+1] = fin ;
    K += 2 ;
    sort( imp+1, imp+K-1 ) ;

    for( int i=0; i<K; i++ )
        dijkstra(imp[i]) ;

    do {
        int tmp=0, pos=ini;
        for( int i=0; i<K; i++, pos=imp[i-1] )
            tmp += minP[pos][imp[i]]-1 ;
        res = min( res, tmp ) ;
    }while( next_permutation(imp+1, imp+K-1) ) ;

    printf("%d\n", res ) ;

    return 0 ;
}
