#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10000000

int dp[lim], marc[lim] ;
int fact[10] ;

int memo(int pos) {
	if( dp[pos]!=-1 )  {
		if( dp[pos]==0 )
			marc[pos] = 1 ;
		return dp[pos] ;
	}
	dp[pos] = 0 ;
	int a = 0, w=pos ;
	while( pos ) {
		a += fact[pos%10] ;
		pos /= 10 ;
	}
	
	memo(a) ;
	dp[w] = memo(a)+1 ;
	if( marc[w] ) {
		pos = w ;
		do {
			a = 0 ;
			while( pos ) {
				a += fact[pos%10] ;
				pos /= 10 ;
			}
			pos = a ;
			dp[a] = dp[w] ;
		} while( pos!=w ) ;
	}
	
	return dp[w] ;
}

int main() {
	int N ;
	int res = 0 ;
	
	fact[0] = 1 ;
	for( int i=1; i<10; i++ ) 
		fact[i] = fact[i-1]*i ;
		
	for( int i=0; i<lim; i++ )
		dp[i] = -1 ;
		
	scanf("%d", &N ) ;
	for( int i=1; i<=N; i++ ) {
		if( memo(i)==60 )
			res ++ ;
	}
	cout << res << endl ;
	
	return 0 ;
}
