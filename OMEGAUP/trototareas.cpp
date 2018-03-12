#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 100005 ;

int N, W ;
int dp[lim] ;

int main() {
	int res = (1<<29) ;
	
	scanf("%d%d", &N, &W ) ;
	for( int i=1; i<lim; i++ )
		dp[i] = (1<<29) ;
	
	for( int i=0; i<N; i++ ) {
		int v, t ;
		scanf("%d%d", &v, &t ) ;
		for( int j=lim-1; j>=v; j-- ) 
			dp[j] = min( dp[j], dp[j-v] + t ) ;
	}
	
	for( int i=W; i<lim; i++ )
		res = min( res, dp[i] ) ;
		
	printf("%d\n", res ) ;
	
	return 0 ;
}
