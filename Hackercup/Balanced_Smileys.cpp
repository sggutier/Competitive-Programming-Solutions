#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <stack>
using namespace std ;
const int lim = 105 ;

int N ;
char S[lim] ;
bool dp[lim][lim] ;

bool caso() {
	gets(S) ;
	N = strlen(S) ;

	for( int i=0; i<N; i++ )
		dp[N][i] = 0 ;
	dp[N][0] = 1 ;
	for( int i=N-1; i>=0; i-- ) {
		if( S[i]=='(' ) {
			for( int j=0; j<N; j++ ) {
				dp[i][j] = dp[i+1][j+1] ;
			}
		}
		else if( S[i]==')' ) {
			for( int j=0; j<N; j++ ) {
				dp[i][j] = 0 ;
				if( j )
					dp[i][j] = dp[i+1][j-1] ;
			}
		}
		else {
			for( int j=0; j<N; j++ ) {
				dp[i][j] = dp[i+1][j] ;
			}
			if( i+1<N && S[i]==':' && (S[i+1]=='(' || S[i+1]==')')  ) {
				for( int j=0; j<N; j++ ) {
					dp[i][j] |= dp[i+2][j] ;
				}
			}
		}
	}

	return dp[0][0] ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	gets(S) ;
	for( int i=1; i<=T; i++ ) {
		printf("Case #%d: %s\n", i, caso()? "YES":"NO" ) ;
	}

	return 0 ;
}

