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
#include <list>
#include <stack>
using namespace std ;
const int lim = 10005 ;
const int mod = 1000000007 ;

int N ;
int arr[lim] ;
int dp[2][lim] ;

int main() {
	int ant=0, sig=1 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;

	if( arr[0]>0 ) {
		printf("0\n" ) ;
		return 0 ;
	}

	dp[0][0] = 1 ;
	for( int i=1; i<N; i++, swap(ant,sig) ) {
		if( arr[i]!=-1 ) {
			for( int j=0; j<N; j++ ) {
				dp[sig][j] = 0 ;
				if( j==arr[i] ) {
					dp[sig][j] = dp[ant][j] ;
					if( j+1<N )
						dp[sig][j] = (dp[sig][j] + dp[ant][j+1])%mod ;
					if( j-1>=0 )
						dp[sig][j] = (dp[sig][j] + dp[ant][j-1])%mod ;
				}
			}
		}
		else {
			for( int j=0; j<N; j++ ) {
				dp[sig][j] = dp[ant][j] ;
				if( j+1<N )
					dp[sig][j] = (dp[sig][j] + dp[ant][j+1])%mod ;
				if( j-1>=0 )
					dp[sig][j] = (dp[sig][j] + dp[ant][j-1])%mod ;
			}
		}
	}

	printf("%d\n", dp[ant][0] ) ;

	return 0 ;
}


