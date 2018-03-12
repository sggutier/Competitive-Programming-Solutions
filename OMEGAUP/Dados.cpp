#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 105 ;

int N, K ;
long long dp[lim][lim] ;
int arr[lim] ;

int main() {
	int res = 0 ;

	scanf("%d", &N ) ;
	for( int i=1; i<=N; i++ ) 
		scanf("%d", &arr[i] ) ;

	sort( arr+1, arr+N+1 ) ;

	K = arr[N] ;
	for( int i=1; i<=K; i++ )
		dp[0][i] = 1 ;
	for( int i=1; i<=N; i++ ) {
		for( int j=1; j<=K; j++ ) {
			dp[i][j] = dp[i][j-1] ;
			if( j<=arr[i] )
				dp[i][j] += dp[i-1][j] ;
		}
	}

	cout << dp[N][arr[N]] << endl ;

	return 0 ;
}
