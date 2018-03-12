#include <cstdio>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std ;

int N, W ;
list <int> adj[1000] ;
bool usd[1000] ;

int main() {
    int res=0, imp=0 ;

    scanf("%d%d", &N, &W ) ;
    for( int i=0; i<W; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }

    usd[0] = 1 ;
    for( int i=1; i<=N; i++ ) {
        if( usd[i] || adj[i].size()>1 )
            continue ;
        int pos=i, ant=-1, k=0, sig ;

        while( !usd[pos] ) {
            k ++ ;
            usd[pos] = 1 ;
            sig = 0 ;
            for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
                if( *it==ant )
                    continue ;
                sig = *it ;
            }
            ant = pos ;
            pos = sig ;
        }

        if( pos==0 ) {
            if( k%2==1 )
                imp ++ ;
        }
        else {
            res += k%2 ;
        }
    }
    for( int i=1; i<=N; i++ ) {
        if( usd[i] )
            continue ;
        int pos=i, ant=-1, k=0, sig ;

        while( !usd[pos] ) {
            k ++ ;
            usd[pos] = 1 ;
            sig = 0 ;
            for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
                if( *it==ant )
                    continue ;
                sig = *it ;
            }
            ant = pos ;
            pos = sig ;
        }

        if( pos==0 ) {
            if( k%2==1 )
                imp ++ ;
        }
        else {
            res += k%2 ;
        }
    }

    printf("%d\n", res+imp%2 ) ;

    return 0 ;
}
