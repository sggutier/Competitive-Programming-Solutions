#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
using namespace std ;
#define lim 1005

int N ;
set <int>  adj[lim] ;
bool usd[lim] ;

int main() {
    int M, res=0 ;
    queue <int> Q ;


    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<M; i++  )   {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        a--, b-- ;
        adj[a].insert(b) ;
        adj[b].insert(a) ;
    }


    for( int i=0; i<N; i++ ) {
        if( adj[i].size() == 1 )
            Q.push(i);
    }


    while( !Q.empty()  )  {
        while( !Q.empty()  )  {
            int pos = Q.front() ;
            set <int> :: iterator it = adj[pos].begin() ;
            Q.pop() ;

            usd[pos] = 1 ;
            adj[*it].erase(pos) ;
        }


        for( int i=0; i<N; i++ ) {
            if( adj[i].size() == 1 && !usd[i]  )
                Q.push(i);
        }

        res ++ ;
    }

    cout << res << endl ;

    return 0 ;
}
