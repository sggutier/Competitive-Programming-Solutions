#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

void caso() {
	int K, N ;
	int arr[1000] ;
	bool obg[1000] ;
	int dp[50][50] ;

	memset( dp, 0, sizeof(dp) ) ;
	memset( obg, 0, sizeof(obg) ) ;

	scanf("%d%d", &K, &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		obg[ arr[i] ] = 1 ;
	}

	K *= 2 ;
	dp[0][0] = 1 ;
	for( int i=1; i<=K; i++ ) {
		for( int j=0; j<=K; j++ ) {
			if( j )
				dp[i][j] += dp[i-1][j-1] ;
			if( !obg[i] )
				dp[i][j] += dp[i-1][j+1] ;
		}
	}

	printf("%d\n", dp[K][0] ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ )
		caso() ;

	return 0 ;
}
