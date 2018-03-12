#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define mod 1000000007
#define lim 105

int dp[lim][lim] ;

void caso() {
    int N, M ;
    int i, j ;
    int a, b, sum ;
    bool chafa = 0 ;

    memset( dp, sizeof(dp),  0   ) ;
    dp[0][0] = 1 ;

    scanf("%d%d", &M, &N ) ;
    for( i=1; i<=N; i++ ) {
        scanf("%d%d", &a, &b ) ;
        if( chafa )
            continue ;
        if( b<a ) {
            chafa = 1 ;
            continue ;
        }
        sum = 0 ;
        for( j=0; j<=M; j++ ) {
            if( j-a>=0  ) {
                sum += dp[i-1][j-a] ;
				sum %= mod ;
			}
            if( j-b-1 >= 0  ) {
                sum += mod - dp[i-1][j-b-1] ;
				sum %= mod ;
			}
            dp[i][j] = sum ;
        }
    }

    if( chafa  )
        printf("0\n" ) ;
    else
        printf("%d\n", dp[N][M] ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
        caso() ;
    }

    return 0 ;
}
