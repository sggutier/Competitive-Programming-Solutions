#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std ;
#define lim 205

int N ;
int comp[lim], deg[lim], deg2[lim] ;
list <int> adj[lim] ;
queue <int> Q[3] ;

int main() {
    int res = (1<<30), act=0 ;
    int qRes = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &comp[i] ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &deg[i] ) ;
        deg2[i] = deg[i] ;
        for( int j=0; j<deg[i]; j++ ) {
            int tmp ;
            scanf("%d", &tmp ) ;
            adj[tmp-1].push_back(i) ;
        }
    }

    for( int W=0; W<3; W++ ) {
        qRes = -1 ;
        act = W ;
        for( int i=0; i<N; i++ ) {
            deg[i] = deg2[i] ;
            if( deg[i]==0 )
                Q[ comp[i]-1 ].push(i) ;
        }
        while( !Q[0].empty() || !Q[1].empty() || !Q[2].empty() ) {

            while( !Q[act].empty() ) {
                int pos = Q[act].front() ;
                Q[act].pop() ;
                qRes ++ ;
                for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end();  it++  ) {
                    deg[*it] -- ;
                    if( deg[*it]==0 )
                        Q[ comp[*it]-1 ].push(*it) ;
                }
            }
            act = (act+1)%3 ;
            qRes ++ ;

        }

        res = min( res, max(qRes,0)  ) ;

    }

    printf("%d\n", max(res,0)  ) ;

    return 0 ;
}
