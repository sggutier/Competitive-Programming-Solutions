#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 3000

int W = 0 ;
int carg[lim], res[lim] ;

int main() {
    int N, M, K ;
    int cnt = 0 ;

    scanf("%d%d%d", &N, &M, &K ) ;
    M += N ;

    for( int i=0; i<K; i++ )
        res[W++] = 0 ;
    carg[0] = K ;
    carg[N] -= K ;

    for( int i=0; i<M; i++ ) {
        cnt += carg[i] ;
        if( cnt>=K )
            continue ;
        if( cnt==0 ) {
            cnt += K ;
            carg[i-1] ++ ;
            carg[i+N-1] -- ;
            carg[i] += K-1 ;
            carg[i+N] -= K-1 ;
            res[W++] = i-1 ;
            for( int j=1; j<K; j++ )
                res[W++] = i ;
        }
        else {
            int tmp = K-cnt ;
            cnt = K ;
            carg[i] += tmp ;
            carg[i+N] -= tmp ;
            for( int j=0; j<tmp; j++ )
                res[W++] = i ;
        }
    }
    cnt += carg[M] ;
    if( cnt==0 ) {
        res[W++] = M-1 ;
    }

    printf("%d\n", W ) ;
    for( int i=0; i<W; i++ )
        printf("%d ", res[i]+1 ) ;
    printf("\n" ) ;

    return 0 ;
}
