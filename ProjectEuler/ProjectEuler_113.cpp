#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

long long dp[1000][10] ;
long long dp2[1000][10] ;

int main() {
	int N ;
	long long res=9LL ;
	
	cin >> N ;
	
	for( int i=0; i<10; i++ ) {
		dp[0][i] = 1LL ;
		dp2[0][i] = 1LL ;
	}
		
	for( int i=1; i<N; i++ ) {
		dp[i][0] = 1LL ;
		for( int j=1; j<10; j++ ) {
			dp[i][j] = 0LL ;
			for( int k=0; k<=j; k++ )
				dp[i][j] += dp[i-1][k] ;
			printf("%lld ", dp[i][j] ) ;
			res += dp[i][j] ;
		}
		printf("\n" ) ;
		
		dp2[i][9] = 1LL ;
		res ++ ;
		for( int j=8; j>=0; j-- ) {
			dp2[i][j] = 0LL ;
			for( int k=0; k<=j; k++ )
				dp2[i][j] += dp2[i-1][k] ;
			if( j )
				res += dp2[i][j] ;
			printf("%lld ", dp2[i][j] ) ;
		}
		printf("\n\n" ) ;
		
		res -= 9LL ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
