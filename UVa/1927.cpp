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
const int lim = 20005 ;
typedef pair<int,int> par ;
#define f first
#define s second

int N ;
list <par> adj[lim] ;
int minP[lim] ;
priority_queue <par> Q ;

void caso() {
	int E, ini, fin ;

	memset( minP, 0, sizeof(minP) ) ;
	for( int i=0; i<lim; i++ )
		adj[i].clear() ;

	scanf("%d", &N ) ;
	scanf("%d%d%d", &E, &ini, &fin ) ;
	for( int i=0; i<E; i++ )  {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		adj[a].push_back( par(c,b) ) ;
		adj[b].push_back( par(c,a) ) ;
	}

	minP[ini] = 1 ;
	Q.push( par(-1,ini) ) ;
	while( !Q.empty() ) {
		par W = Q.top() ;
		Q.pop() ;
		int pos=W.s, crg=-W.f ;

		if( minP[pos]!=crg )
			continue ;

		for( list<par>::iterator it = adj[pos].begin(); it!=adj[pos].end(); it++ ) {
			if( minP[ it->s]==0 || minP[ it->s ] > crg + it->f ) {
				minP[ it->s ] = crg + it->f ;
				Q.push( par( -minP[it->s], it->s )  ) ;
			}
		}
	}

	if( minP[fin] )
		printf("%d\n", minP[fin]-1 ) ;
	else
		printf("unreachable\n" ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) {
		printf("Case #%d: ", i+1 ) ;
		caso() ;
	}

	return 0 ;
}


