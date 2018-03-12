#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 10005 ;
const int mod = 1000000009 ;

int N, K ;
int dp[2][lim] ;

int main() {
	int res = 0 ;
	int act=0, sig=1 ;

	scanf("%d%d", &N, &K ) ;

	if( N>=lim || K>=lim ) {
		while(1) {
		}
		return 0 ;
	}

	dp[0][0] = 1 ;
	for( int i=0; i<=N; i++, swap(act,sig) ) {
		if( i ) 
			dp[act][0] = 0 ;
		for( int j=1; j<=K; j++ ) {
			dp[act][j] = dp[act][j-1] ;
			if( i )
				dp[act][j] = (dp[act][j]+dp[sig][j])%mod ;
			//printf("%d %d -> %d\n", i, j, dp[act][j] ) ;
		}
		res = (res+dp[act][K] ) ;
	}

	printf("%d\n", res ); 

	return 0 ;
}

