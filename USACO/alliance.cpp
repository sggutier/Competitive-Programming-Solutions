#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <map>
using namespace std ;
#define mod 1000000007LL
#define f first
#define s second
#define lim 1000005

int N, E ;
map<int,int> adj[lim] ;
int dis[lim] ;
int Q ;

int busca( int pos, int prof ) {
	if( dis[pos] ) {
		Q = prof-dis[pos] ;
		return 0 ;
	}
	int res = 1 ;
	dis[pos] = prof ;
	for( map<int,int>::iterator it=adj[pos].begin();  it!=adj[pos].end();  it++  ) {
		if( (*it).s ) {
			(*it).s -- ;
			adj[(*it).f][pos] -- ;
			res += busca( (*it).f, prof+1 ) ;
		}
	}
	return res ;
}

int main() {
	freopen( "alliance.in", "r", stdin ) ;
	freopen( "alliance.out", "w", stdout ) ;
	
	long long res = 1LL ;
	
	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		if( adj[a].find(b) == adj[a].end()  )
			adj[a][b] = 0 ;
		adj[a][b] ++ ;
		if( adj[b].find(a) == adj[b].end()  )
			adj[b][a] = 0 ;
		adj[b][a] ++ ;
	}
	
	for( int i=0; i<N; i++ ) {
		if( dis[i] )
			continue ;
		Q = 0 ;
		int tmp = busca( i, 1 ) ;
		if( Q )
			res = (res*2LL)%mod ;
		else
			res = (res*tmp)%mod ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
