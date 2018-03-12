#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#include <list>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define lim 3000
#define inf (1<<30)

int N ;
list <int> adj[lim] ;
int antCol[lim], minP[lim] ;
queue <par> Q ;

int main() {
    int W, ini, fin ;
    char S[lim] ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        int a, b ;
        scanf("%s", S ) ;
        a = S[0] ;
        scanf("%s", S ) ;
        b = S[0] ;
        adj[a].push_back(b) ;
        adj[b].push_back(a) ;
    }
    scanf("%d", &W ) ;
    scanf("%s", S ) ;
    ini = S[0] ;
    scanf("%s", S ) ;
    fin = S[0] ;

    for( int i=lim-1; i>=0; i-- ) {
        int x = i/20 ;
        if( i%20 ) x ++ ;
        antCol[i-x] = i ;
        minP[i] = inf ;
    }

    minP[fin] = W ;
    Q.push( par(-minP[fin],fin)   )  ;
    while( !Q.empty()   )  {
        par pos = Q.front() ;
        Q.pop() ;
        if( minP[pos.s] != -pos.f   )
            continue ;
        pos.f *= -1 ;

        int a ;
        if( pos.s>='A' && pos.s<='Z' ) {
            for( list<int>::iterator  it=adj[pos.s].begin();   it!=adj[pos.s].end();  it++    )   {
                a = antCol[pos.f] ;
                if( minP[*it]>a ) {
                    minP[*it] = a ;
                    Q.push( par(-a,*it)  ) ;
                }
            }
        }
        else {
            for( list<int>::iterator  it=adj[pos.s].begin();   it!=adj[pos.s].end();  it++    )   {
                a = pos.f+1 ;
                if( minP[*it]>a ) {
                    minP[*it] = a ;
                    Q.push( par(-a,*it)  ) ;
                }
            }
        }
    }

    printf("%d\n", minP[ini] ) ;

    return 0 ;
}
