#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
using namespace std ;
#define lim 1000

int diam( int pos, int ant, int &maxDiam, list<int> adj[] ) {
	int a=0, b=0 ;
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( *it==ant )
			continue ;
		b = max( b, diam(  *it,  pos,  maxDiam, adj )+1  );
		if( b>a )
			swap(a,b) ;
	}
	maxDiam = max(maxDiam, a+b ) ;
	return a ;
}

void caso(int &res) {
	int N, W=0 ;
	list<int> adj[lim] ;
	
	scanf("%d", &N ) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}
	
	diam( 0, -1, W, adj ) ;
	
	res += W ;
}

int main() {
	freopen( "input.txt", "r", stdin ) ;
	freopen( "output.txt", "w", stdout ) ;
	
	int T, res=0 ;
	
	scanf("%d", &T ) ;
	
	for( int i=0; i<T; i++ ) {
		caso(res) ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
