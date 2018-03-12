#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
using namespace std ;
#define lim 100005

int N ;
list <int> adj[lim] ;
int le[lim], ro[lim] ;
int res = 0 ;

int busca( int pos, int ant ) {
    le[pos] = 0 ;
    ro[pos] = 0 ;
    for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
        if( *it!=ant ) {
            le[pos] = max( le[pos], busca(*it,pos)  ) ;
            if( le[pos]>ro[pos] )
                swap( ro[pos], le[pos] ) ;
        }
    }
    res = max( res, ro[pos]+le[pos] ) ;
    return ro[pos]+1 ;
}

int main() {
    scanf("%d", &N ) ;
    for( int i=1; i<N; i++ ) {
        int a, b ;
        scanf("%d%d", &a,&b ) ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    busca(1,-1) ;

    printf("%d\n", res ) ;

    return 0 ;
}

