#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 105 ;

int N, M ;
int arr[lim][lim] ;
int dp[lim][lim] ;

void caso() {
	int res = -(1<<30) ;
	memset( dp, 0, sizeof(dp) ) ;
	scanf("%d%d", &N, &M ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<M; j++ ) 
			scanf("%d", &arr[i][j] ) ;
	for( int j=0; j<M; j++ )
		dp[N-1][j] = arr[N-1][j] ;
	
	for( int i=N-2; i>=0; i-- ) {
		for( int j=0; j<M; j++ ) {
			dp[i][j] = dp[i+1][j] ;
			if( j )
				dp[i][j] = max( dp[i][j], dp[i+1][j-1] ) ;
			if( j<M-1 )
				dp[i][j] = max( dp[i][j], dp[i+1][j+1] ) ;
			dp[i][j] += arr[i][j] ;
		}
	}

	for( int j=0; j<M; j++ )
		res = max( res, dp[0][j] ) ;

	printf("%d\n", res ) ;
}

int main() {
	int T = 0 ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ )
		caso() ;

	return 0 ;
}
