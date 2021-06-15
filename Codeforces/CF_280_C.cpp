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
const int lim = 100005 ;

int N ;
list <int> adj[lim] ;
int prof[lim] ;

void dfs( int pos, int ant, int p ) {
	prof[pos] = p ;
	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++  )
		if( ant!=(*it) )
			dfs( *it, pos, p+1 ) ;
}

int main() {
	double res = 1.0*0 ;

	scanf("%d", &N ) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back(b) ;
		adj[b].push_back(a) ;
	}

	dfs( 0, -1, 1 ) ;

	for( int i=0; i<N; i++ )
		res += 1.0/prof[i] ;

	printf("%.10lf\n", res ) ;

	return 0 ;
}


