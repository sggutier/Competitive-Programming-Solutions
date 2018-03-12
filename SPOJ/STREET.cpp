#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std ;
const int lim = 500 ;

int N, M, T ;
int arr[lim] ;
int dp[lim][lim] ;

int main() {
	scanf("%d%d%d", &N, &M, &T ) ;
	for( int i=1; i<=N; i++ ) 
		scanf("%d", &arr[i] ) ;

	for( int i=1; i<=N; i++ ) {
		for( int j=1; j<=M; j++ ) {
			dp[i][j] = dp[i-1][j] ;
			for( int k=i, w=arr[i]; i-k<=T && k>0; k-- ) {
				w = min( arr[k], w ) ;
				dp[i][j] = max( dp[i][j], dp[k-1][j-1] + (i-k+1)*w ) ;
			}
		}
	}

	int res = 0 ;
	for( int i=0; i<=M; i++ )
		res = max( res, dp[N][i] ) ;

	printf("%d\n", res ) ;

	return 0 ;
}
