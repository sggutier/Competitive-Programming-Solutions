#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
#define lim 5005
#define mod 1000000007

int N, M ;
char S[lim], W[lim] ;
int dp[lim][lim] ;

int main() {
	int res = 0 ;
	
	gets(S) ;
	gets(W) ;
	N = strlen(S) ;
	M = strlen(W) ;
	
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<M; j++ ) {
			dp[i+1][j+1] = dp[i+1][j] ;
			if( S[i]==W[j] ) {
				dp[i+1][j+1] += dp[i][j]+1 ;
				dp[i+1][j+1] %= mod ;
			}
		}
		res = (res+dp[i+1][M])%mod ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
