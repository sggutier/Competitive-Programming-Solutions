#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

bool choc[44777778] ;

int main() {
    int N, M ;
    long long i, j ;
    long long res = 0LL ;
    int V=6, C=6;
    int tmp ;

    scanf("%d%d",&N,&M ) ;
    for( i=0; i<M; i++ ) {
        scanf("%d",&tmp ) ;
        choc[tmp] = 1 ;
    }
    res += 4LL*N ;

    for( i=0LL+N; i; i-- ) {
        if( choc[i] ) {
            C = (C+1)%7 ;
            if( !C  )
                res += 2*i +47LL ;
        }
        else {
            V = (V+1)%7 ;
            if( !V )
                res += 2*i +47LL ;
        }
    }

    cout << res << endl ;

    return 0 ;
}
