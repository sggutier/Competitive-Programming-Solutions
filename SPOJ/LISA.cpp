#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std ;
const int lim = 105 ;

void caso( int numCaso ) {
	int N = 0, M=0 ;
	unsigned long long arr[lim] ;
	char S[lim], simb[lim] ;
	unsigned long long dp[lim][lim], dp2[lim][lim], carg=0ULL ;

	scanf("%s", S ) ;
	M = strlen(S) ;

	for( int i=0; i<M; i++ ) {
		if( S[i]>='0' && S[i]<='9' ) 
			carg = carg*10ULL + S[i]-'0' ;
		else {
			arr[N] = carg ;
			carg = 0ULL ;
			simb[N++] = S[i] ;
		}
	}
	arr[N] = carg ;
	dp[N+1] = 0ULL ;
	dp2[N+1] = 0ULL ;

	for( int i=N; i>=0; i-- ) {
		dp[i][i] = arr[i] ;
		dp2[i][i] = arr[i] ;
		for( int k=i+1; k<=N; k++ ) {
			dp[i][k] = 0ULL ;
			dp2[i][k] = (1ULL<<63) - 1ULL + (1ULL<<63) ;

			for( int j=i+1; j<=k; j++ ) {
				if( simb[j-1]=='*' ) {
					dp[i][k] = max( dp[i][k], dp[i][j-1]*dp[j][k] ) ;
					dp2[i][k] = min( dp2[i][k], dp2[i][j-1]*dp2[j][k] ) ;
				}
				else {
					dp[i][k] = max( dp[i][k], dp[i][j-1]+dp[j][k] ) ;
					dp2[i][k] = min( dp2[i][k], dp2[i][j-1]+dp2[j][k] ) ;
				}
			}
		}	
	}

	cout << dp[0][N] << " " << dp2[0][N] << endl ;

}

int main() {
	int Q ;

	scanf("%d", &Q ) ;

	for( int i=0; i<Q; i++ )
		caso(Q) ;

	return 0 ;
}
