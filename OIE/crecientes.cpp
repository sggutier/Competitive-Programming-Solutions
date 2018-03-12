#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;
#define lim 1000

string S ;

int caso() ;

int main() {
	char A[lim] ;
	
	while( scanf("%s", A ) != EOF  )  {
		S = A ;
		printf("%d\n", caso() );
	}
	
	return 0 ;
}

int caso() {
	int N = S.size() ;
	int dp[lim] ;
	int res = 0 ;
	
	for( int i=N-1; i>=0; i-- ) {
		dp[i] = 1 ;
		for( int j=i+1; j<N; j++ ) {
			if( S[i]<S[j] )
				dp[i] += dp[j] ;
		}
		res += dp[i]-1 ;
	}
	
	return res ;
}
