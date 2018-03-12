#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 50005 ;

int N ;
char S[lim] ;
int dp[lim] ;

int main() {
	freopen( "cowfind.in", "r", stdin ) ;
	freopen( "cowfind.out", "w", stdout ) ;

	int res = 0LL ;

	scanf("%s", S ) ;
	N = strlen(S) ;

	for( int i=N-2; i>=0; i-- )  {
		dp[i] = dp[i+1] ;
		if( S[i]==')' && S[i+1]==')'  )
			dp[i] ++ ;
		if( S[i]=='(' && S[i+1]=='(' )
			res += dp[i+2] ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}

