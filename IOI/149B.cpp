#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
    char S[20] ;
    int A[10], B[10] ;
    int N=0, M=0 ;
    int W=0, K=1 ;
    int res = 0 ;

    scanf("%s", S ) ;
    for( W=0; S[W]!=':'; W++ ) {
        if( S[W]>='0' && S[W]<='9' )
            A[N++] = S[W]-'0' ;
        else
            A[N++] = S[W]-'A'+10 ;
        K = max( K, A[N-1] ) ;
    }
    for( W++; S[W]>0; W++ ) {
        if( S[W]>='0' && S[W]<='9' )
            B[M++] = S[W]-'0' ;
        else
            B[M++] = S[W]-'A'+10 ;
        K = max( K, B[M-1] ) ;
    }

    W = K ;
    for( K=W+1; K<100; K++ ) {
        long long sum = 0LL ;
        for( long long i=N-1, pot=1LL; i>=0; i--, pot*=K )
            sum += A[i]*pot ;
        if( sum>=24 )
            continue ;

        sum = 0LL ;
        for( long long i=M-1, pot=1LL; i>=0; i--, pot*=K )
            sum += B[i]*pot ;
        if( sum>=60 )
            continue ;

        res ++ ;
    }

    if( res>60 ) {
        printf("-1\n" ) ;
        return 0 ;
    }
    if( res==0 ) {
        printf("0\n" ) ;
        return 0 ;
    }

    for( K=W+1; K<100; K++ ) {
        long long sum = 0LL ;
        for( long long i=N-1, pot=1LL; i>=0; i--, pot*=K )
            sum += A[i]*pot ;
        if( sum>=24 )
            continue ;

        sum = 0LL ;
        for( long long i=M-1, pot=1LL; i>=0; i--, pot*=K )
            sum += B[i]*pot ;
        if( sum>=60 )
            continue ;

        printf("%d ", K ) ;
    }
    printf("\n" ) ;

    return 0 ;
}
