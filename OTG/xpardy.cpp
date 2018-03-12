#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <utility>
#include <cstring>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define lim 30

par adj[lim] ;

int main() {
    int N, M ;
    int fin ;
    int a, b, c, d ;
    int i, j ;
    long long comb[lim], comb2[lim] ;
    char S[5] ;

    scanf("%d",&N ) ;
    for( i=0; i<N; i++ ) {
        scanf("%s",S ) ;
        a = S[0]-'A' ;
        scanf("%s",S ) ;
        b = S[0]-'A' ;
        scanf("%s",S ) ;
        c = S[0]-'A' ;
        scanf("%s",S ) ;
        if( S[0] != '-' )
            fin = i ;
        adj[i*2+0] = par( a, b ) ;
        adj[i*2+1] = par( a, c ) ;
    }
    scanf("%d",&M ) ;

    for( i=0; i<N; i++ )
        comb[i] = 0LL ;
    comb[0] = 1LL ;

    for( i=0; i<M; i++ ) {
        memset( comb2, 0, sizeof(comb2)  ) ;
        for( j=0; j<2*N; j++ )
            comb2[ adj[j].s ] += comb[ adj[j].f ]  ;
        memcpy (comb,comb2,N+1 );

    }

    cout << comb[fin] << endl ;

    return 0 ;
}
