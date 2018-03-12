#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
using namespace std ;
typedef list<int>::iterator ito;
#define lim 100005

int N, K ;
list<int> li[lim] ;
int carg[lim], res[lim] ;
bool usd[lim] ;

void dfs( int ini, int pos, int dis ) {
	if( dis<0 ) 
		return ;
		
	usd[pos] = 1 ;
	res[ini] += carg[pos] ;
	for( ito it=li[pos].begin(); it!=li[pos].end(); it++ ) {
		if( !usd[*it] ) 
			dfs( ini, *it, dis-1 ) ;
	}
	usd[pos] = 0 ;
}

int main() {
	freopen( "nearcows.in", "r", stdin ) ;
	freopen( "nearcows.out", "w", stdout ) ;
	
	scanf("%d%d", &N, &K ) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		li[a].push_back(b) ;
		li[b].push_back(a) ;
	}
	for( int i=0; i<N; i++ ) 
		scanf("%d", &carg[i] ) ;
		
	for( int i=0; i<N; i++ ) {
		dfs( i, i, K ) ;
		printf("%d\n", res[i] ) ;
	}
	
	return 0 ;
}
