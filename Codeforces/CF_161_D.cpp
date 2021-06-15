#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
using namespace std ;
#define limK 505
#define limN 50007

int N, K ;
list<int> adj[limN] ;
long long dic[limN][limK] ;
long long res = 0LL ;

void dfs( int pos, int ant ) {
	long long a = 0LL ;
	dic[pos][0] = 1LL ;
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( *it==ant )
			continue ;
		dfs( *it, pos ) ;
		for( int i=0; i<K; i++ ) 
			dic[pos][i+1] += dic[*it][i] ;
	}
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( *it==ant )
			continue ;
		res += dic[pos][0] * dic[*it][K-1] ;
		for( int i=1; i<K; i++ ) 
			a += (dic[pos][K-i]-dic[*it][K-i-1]) * dic[*it][i-1];
	}
	res += a/2LL ;
	
}

int main() {
	scanf("%d%d", &N, &K ) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}
	
	dfs( 0, 0 ) ;
	
	cout << res << endl ;
	
	return 0 ;
}
