#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>
using namespace std ;

int N, K ;
int dp[50][50] ;
int mad[50] ;

int memo( int pI, int pF, int mI, int mF ) {
    if( pI>pF )
	return 0 ;
    if( dp[pI][pF] )
	return dp[pI][pF] ;
    dp[pI][pF] = (1<<30) ;
    for( int i=pI; i<=pF; i++ )
	dp[pI][pF] = min( dp[pI][pF], memo( pI, i-1, mI, mad[i] ) + memo( i+1, pF, mad[i], mF ) ) ;
    return dp[pI][pF] += mF-mI ;
}

void caso() {
    memset( dp, 0, sizeof(dp) ) ;
    scanf("%d",&N) ;
    for( int i=0; i<N; i++ )
	scanf("%d",&mad[i] ) ;
    printf("The minimum cutting is %d.\n", memo(0,N-1,0,K) ) ;
}

int main() {
    while( scanf("%d",&K)!=EOF &&K )
	caso() ;
    
    return 0 ;
}
