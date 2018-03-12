#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;

unsigned long long dp[100][100] ;

int main() {
	int N, M ;

	scanf("%d%d", &N, &M ) ;
	dp[0][0] = 1ULL ;
	for( int i=0; i<=N; i++ ) {
		for( int j=0; j<=M; j++ ) {
			if( i )
				dp[i][j] += dp[i-1][j] ;
			if( j )
				dp[i][j] += dp[i][j-1] ;
		}
	}

	cout << dp[N][M] << endl ;

	return 0 ;
}

