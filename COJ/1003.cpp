#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cstring>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second

void caso() {
    int N, M ;
    par rep[1000] ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ )
        rep[i] = par( 0, i ) ;
    for( int i=0; i<M; i++ ) {
        for( int j=0; j<N; j++ ) {
            int a ;
            scanf("%d", &a ) ;
            rep[j].f += a ;
        }
    }

    sort( rep, rep+N ) ;

    printf("%d\n", rep[N-1].s+1 ) ;

    return ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
        caso() ;
    }

    return 0 ;
}
