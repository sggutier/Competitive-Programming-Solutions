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
const int lim = 2005 ;

int N = 0 ;
int nDiv[lim] ;
map <int,int> wDiv ;
long long dp[lim][lim] ;
bool usd[lim][lim] ;

long long memo( int W, int ultD ) {
	if( W==0 )
		return 1LL ;
	if( usd[W][ultD] ) {
		return dp[W][ultD] ;
	}

	usd[W][ultD] = 1 ;

	for( int i=ultD; i<N && nDiv[i]<=nDiv[W]; i++ ) {
		if( nDiv[W]%nDiv[i] )
			continue ;
		dp[W][ultD] += memo( wDiv[nDiv[W]/nDiv[i]] , i ) ;
	}

	return dp[W][ultD] ;
}

int main() {
	int W ;
	int K ;

	scanf("%d", &W ) ;

	for( K=2; K*K<W; K++ ) {
		if( W%K )
			continue ;
		nDiv[N++] = K ;
		nDiv[N++] = W/K ;
	}
	if( K*K==W )
		nDiv[N++] = K ;

	if( N==0 ) {
		printf("0\n" ) ;
		return 0 ;
	}

	nDiv[N++] = 1 ;
	sort( nDiv, nDiv+N ) ;
	nDiv[N] = W ;

	for( int i=0; i<=N; i++ )
		wDiv[nDiv[i]] = i ;

	printf("%lld\n", memo( N,1 )  ) ;

	return 0 ;
}

