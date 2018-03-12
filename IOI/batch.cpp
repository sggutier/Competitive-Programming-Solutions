#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
#define lim 10005

int N, S ;
int T[lim], F[lim] ;
int dp[lim], sumF[lim] ;

int main() {
    scanf("%d%d", &N, &S ) ;
    for( int i=0; i<N; i++ )
        scanf("%d%d", &T[i], &F[i] ) ;

    for( int i=N-1; i>=0; i-- ) {
        sumF[i] = sumF[i+1] + F[i] ;
    }

    for( int i=N-1; i>=0; i-- ) {
        dp[i] = (1<<30) ;
        for( int j=i, sum=S; j<N; j++ ) {
            sum += T[j] ;
            dp[i] = min( dp[i], sumF[i]*sum + dp[j+1] ) ;
        }
    }

    printf("%d\n", dp[0] ) ;

    return 0 ;
}

