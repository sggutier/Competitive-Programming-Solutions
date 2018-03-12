#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 10005 ;

int N, E ;
list <int> adj[lim] ;
bool usd[lim] ;
bool res = true ;
int vis = 0 ;

void dfs( int pos, int ant ) {
	if( usd[pos] == true ) {
		res = false ;
		return ;
	}
	usd[pos] = true ;
	vis ++ ;
	for( list<int>::iterator it=adj[pos].begin();   it!=adj[pos].end();    it++    ) {
		if(   (*it)==ant   )
			continue ;
		dfs( *it, pos ) ;
	}
}

int main() {
	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}

	if( E!=N-1 ) {
		printf("NO\n" ) ;
		return 0 ;
	}

	dfs( 0, -1 ) ;

	if( vis!=N )
		res = false ;

	if( res==true )
		printf("YES\n" ) ;
	else
		printf("NO\n" ) ;

	return 0 ;
}


