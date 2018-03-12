#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;
const int lim = 5005 ;
const int mod = 1000000007 ;

int dp[lim] ;

int main() {
	int N, M ;
	char A[lim], B[lim] ;
	int res = 0 ;

	gets(A) ;
	gets(B) ;
	N = strlen(A) ;
	M = strlen(B) ;

	for( int i=0; i<M; i++ ) {
		for( int j=N-1; j>=0; j-- ) {
			if( B[i]==A[j] ) {
				dp[j] = (dp[j]+1)%mod ;
				if( j )
					dp[j] = (dp[j] + dp[j-1])%mod ;
			}
		}
	}

	for( int i=0; i<N; i++ )
		res = (res+dp[i])%mod ;

	printf("%d\n", res ) ;

	return 0 ;
}
