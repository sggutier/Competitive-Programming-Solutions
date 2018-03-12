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
const int lim = 1005 ;

int N, K ;
int sig[lim], ant[lim], prof[lim] ;
int dp[lim] ;
bool mrk[lim] ;

int dfs( int pos ) {
	if( pos==0 )
		return 0 ;
	if( prof[pos] )
		return prof[pos] ;
	prof[pos] = dfs(sig[pos]) +1 ;
	mrk[pos] = mrk[sig[pos]] ;
	if( pos==K )
		mrk[pos] = 1 ;
	return prof[pos] ;
}

int main() {
	scanf("%d%d", &N, &K ) ;
	for( int i=1; i<=N; i++ ) 
		scanf("%d", &sig[i] ) ;

	for( int i=1; i<=N; i++ ) {
		ant[sig[i]] = i ;
		dfs(i) ;
	}

	dp[0] = 1 ;
	for( int i=1; i<=N; i++ ) {
		if( ant[i] || mrk[i] )
			continue ;
		for( int j=N; j>=prof[i]; j-- )
			dp[j] |= dp[j-prof[i]] ;
	}

	for( int i=0; i<=N; i++ ) {
		if( dp[i] && i+prof[K]<=N )
			printf("%d\n", i+prof[K] ) ;
	}

	return 0 ;
}


