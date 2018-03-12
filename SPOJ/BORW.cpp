#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
const int lim = 205 ;
const int inf = (1<<30) ;

int dp[lim][lim][lim] ;

void caso( int N ) {
	int res = (1<<30) ;
	int arr[lim] ;

	memset( dp, 0, sizeof(dp) ) ;

	arr[0] = inf ;
	for( int i=1; i<=N; i++ ) 
		scanf("%d", &arr[i] ) ;

	for( int i=1; i<=N; i++ ) {
		for( int j=0; j<=i; j++ ) {
			dp[i][i][j] = inf ;
			dp[i][j][i] = inf ;
		}
		for( int a=0; a<i; a++ ) {
			for( int b=0; b<i; b++ ) {
				dp[i][a][b] = dp[i-1][a][b]+1 ;
				if( arr[i]<arr[a] || a==0 )
					dp[i][i][b] = min( dp[i-1][a][b], dp[i][i][b] ) ;
				if( arr[i]>arr[b] || b==0 )
					dp[i][a][i] = min( dp[i-1][a][b], dp[i][a][i] ) ;
			}
		}
	}

	for( int a=0; a<=N; a++ )
		for( int b=0; b<=N; b++ )
			res = min( res, dp[N][a][b] ) ;

	printf("%d\n", res ) ;
}

int main() {
	int N ;

	scanf("%d", &N ) ;
	while( N!=-1 ) {
		caso(N) ;
		scanf("%d", &N ) ;
	}
}
