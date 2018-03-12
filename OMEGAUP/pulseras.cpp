#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int mod = 1000000007 ;
const int lim = 1000006 ;

int dp[lim][2][2] ;

int main() {
		int N ;
		int res = 0 ;

		scanf("%d", &N ) ;

		dp[0][1][1] = 1 ;
		dp[0][0][0] = 1 ;
		for( int i=1; i<N; i++ ) {
				for( int j=0; j<2; j++ ) {
								dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][1])%mod ;
								dp[i][j][1] = (dp[i][j][1] + dp[i-1][j][0])%mod ;
								dp[i][j][1] = (dp[i][j][1] + dp[i-1][j][1])%mod ;
				}
		}

		res = (res+dp[N-1][0][1])%mod ;
		res = (res+dp[N-1][1][0])%mod ;
		res = (res+dp[N-1][1][1])%mod ;
		printf("%d\n", res ) ;

		return 0 ;
}
