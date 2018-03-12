#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000006

int N ;
char arr[lim] ;
int dp[lim][2] ;

int main() {
	int a, b ;
	
	scanf("%d", &N ) ;
	scanf("%s", arr ) ;
	
	for( int i=0; i<N; i++ )
		arr[i] -= 'A' ;
	
	dp[0][(arr[0]+1)%2] = 1 ;
	for( int i=1; i<N; i++ ) {
		a = arr[i] ;
		b = (arr[i]+1)%2 ;
		
		dp[i][a] = min( dp[i-1][a], dp[i-1][b]+1 ) ;
		dp[i][b] = min( dp[i-1][a]+1, dp[i-1][b]+1 ) ;
	}
	
	printf("%d\n", dp[N-1][0] ) ;
	
	return 0 ;
}
