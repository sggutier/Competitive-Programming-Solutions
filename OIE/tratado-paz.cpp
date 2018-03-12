#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define limP 84
#define limC 4

int A, B ;

long long caso() {
	long long dp[limP][limP][limC][limC] ;
	long long res = 0LL ;
	
	memset( dp, 0LL, sizeof(dp) ) ;
	dp[0][0][0][0] = 1LL ;
	
	for( int i=0; i<A+B; i++ ) {
		int x, y, u, v ;
		for( x=0; x<=i; x++ ) {
			y = i-x ;
			for( u=0, v=0; u<3; u++ ) {
				dp[x+1][y][u+1][v] += dp[x][y][u][v] ;
				if( u ) 
					dp[x][y+1][0][1] += dp[x][y][u][v] ;
			}
			for( u=0, v=0; v<3; v++ ) {
				dp[x][y+1][u][v+1] += dp[x][y][u][v] ;
				if( v )
					dp[x+1][y][1][0] += dp[x][y][u][v] ;
			}
		}
	}
	
	for( int u=0; u<3; u++ ) {
		res += dp[A][B][u][0] ;
		res += dp[A][B][0][u] ;
	}
	
	return res ;
}

int main() {
	while( scanf("%d%d", &A, &B ) != EOF ) {
		cout << caso() << endl ;
	}
	
	return 0 ;
}
