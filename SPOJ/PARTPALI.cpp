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
const int limA = 20 ;
const int limB = 40 ;
const int mod = 1000 ;
typedef unsigned int ui ;

int W ;
ui dp[limA][mod] ;
bool usd[limA][mod] ;
int pot[limB] ;

ui memo( int le, int ro, int crg ) {
	if( le>ro ) 
		return crg==0 ;
	if( usd[le][crg] )
		return dp[le][crg] ;

	dp[le][crg] = 0 ;
	usd[le][crg] = 1 ;
	if( le==ro ) {
		for( int i=0; i<10; i++ ) 
			dp[le][crg] += memo( le+1,ro-1, (crg+i*pot[le])%W )  ;
		return dp[le][crg] ;
	}

	for( int i=0; i<10; i++ ) 
		dp[le][crg] += memo( le+1,ro-1, (crg+i*(pot[le]+pot[ro]) )%W )  ;

	return dp[le][crg] ;
}

void caso() {
	int K ;
	ui res = 0 ;

	memset( usd, 0, sizeof(usd) ) ;

	scanf("%d%d", &W, &K ) ;

	pot[0] = 1 ;
	for( int i=1; i<K; i++ )
		pot[i] = (pot[i-1]*10)%W ;

	if( K==1 ) {
		res = 9/W ;
	}
	else {
		for( int i=1; i<10; i++ ) 
			res += memo( 1,K-2, (i*(pot[0]+pot[K-1]) )%W )  ;
	}
	printf("%d\n", res  ) ;
}

int main() {
	int N ;

	scanf("%d", &N ) ;
	
	for( int i=0; i<N; i++ )
		caso() ;

	return 0 ;
}
