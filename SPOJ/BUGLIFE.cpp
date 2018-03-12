#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>
using namespace std ;
#define limN 2005
#define limI 1000006

int N, E ;
list <int> adj[limN] ;
char tip[limN] ;

bool busca( int pos, int col ) {
    if( tip[pos] != 2 )
        return col == tip[pos] ;
    tip[pos] = col ;
    for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ )
        if( !busca( *it, (col+1)%2 ) )
            return 0 ;
    return 1 ;
}

bool caso() {
    for( int i=0; i<limN; i++ ) {
        tip[i] = 2 ;
        adj[i].clear() ;
    }

    scanf("%d%d", &N, &E ) ;
    for( int i=0; i<E; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    for( int i=1; i<=N; i++ ) {
        if( tip[i] != 2 )
            continue ;
        if( busca(i,0) == 0 )
            return 0 ;
    }
    return 1 ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=1; i<=T; i++ ) {
        if( caso() )
            printf("Scenario #%d:\nNo suspicious bugs found!\n",i) ;
        else
            printf("Scenario #%d:\nSuspicious bugs found!\n",i) ;
    }

    return 0 ;
}
