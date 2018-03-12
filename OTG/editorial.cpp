#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define par2 pair<par,int>
#define f first
#define s second
#define inf (1<<30)

par2 adj[20000] ;

int main() {
    int A, B, N, M, K ;
    int i, j ;
    par2 W ;
    int minC[1000], minC2[1000] ;

    scanf("%d%d%d%d",&A,&B,&N,&K ) ;
    scanf("%d",&M ) ;
    for( i=0; i<M; i++ ) {
        scanf("%d%d%d",&W.f.f,&W.f.s,&W.s ) ;
        adj[2*i] = W ;
        swap( W.f.f, W.f.s ) ;
        adj[2*i+1] = W ;
    }
    M *= 2 ;

    for( i=0; i<N; i++ )
        minC[i] = inf ;
    minC[A] = 0 ;

    for( i=0; i<K; i++ ) {
        for( j=0; j<N; j++ )
            minC2[j] = minC[j] ;
        for( j=0; j<M; j++ )
            minC2[ adj[j].f.s ] = min( minC2[ adj[j].f.s ],  minC[ adj[j].f.f ] + adj[j].s )  ;
        for( j=0; j<N; j++ )
            minC[j] = minC2[j] ;
    }

    printf("%d\n",minC[B] ) ;

    return 0 ;
}
