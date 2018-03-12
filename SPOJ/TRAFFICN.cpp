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
const int lim = 10005 ;
typedef pair<int,int> par ;
#define f first
#define s second

int N ;
list <par> adj[lim*2], bdr[lim*2] ;
int minP[lim*2] ;
priority_queue <par> Q ;

void caso() {
	int E, ini, fin, K, res = (1<<30) ;

	memset( minP, 0, sizeof(minP) ) ;
	for( int i=0; i<lim; i++ ) {
		adj[i].clear() ;
		bdr[i].clear() ;
	}

	scanf("%d", &N ) ;
	scanf("%d%d%d%d", &E, &K, &ini, &fin ) ;
	for( int i=0; i<E; i++ )  {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a --, b-- ;
		adj[a].push_back( par(c,b) ) ;
	}
	for( int i=0; i<K; i++ )  {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b-- ;
		bdr[a].push_back( par(c,b) ) ;
		bdr[b].push_back( par(c,a) ) ;
	}

	ini --, fin -- ;
	minP[ini] = 1 ;
	Q.push( par(-1,ini) ) ;
	while( !Q.empty() ) {
		par W = Q.top() ;
		Q.pop() ;
		int pos=W.s, crg=-W.f, pT, K ;

		if( minP[pos]!=crg )
			continue ;

		pT = pos%lim ;
		K = (pos/lim)*lim ;
		//printf("%d %d -> %d\n", pT, K, crg ) ;
		for( list<par>::iterator it = adj[pT].begin(); it!=adj[pT].end(); it++ ) {
			//printf("    %d %d -> %d\n", it->s, K, crg + it->f ) ;
			//getchar() ;
			if( minP[ it->s +K ]==0 || minP[ it->s +K ] > crg + it->f ) {
				minP[ it->s +K ] = crg + it->f ;
				Q.push( par( -minP[it->s +K], it->s +K )  ) ;
			}
		}
		if( K==0 ) {
			for( list<par>::iterator it = bdr[pT].begin(); it!=bdr[pT].end(); it++ ) {
			//printf("    %d %d -> %d\n", it->s, lim, crg + it->f ) ;
			//getchar() ;
				if( minP[ it->s +lim ]==0 || minP[ it->s +lim ] > crg + it->f ) {
					minP[ it->s +lim ] = crg + it->f ;
					Q.push( par( -minP[it->s +lim], it->s +lim )  ) ;
				}
			}
		}
	}

	res = (1<<30) ;
	if( minP[fin] )
		res = min( res, minP[fin] ) ;
	if( minP[fin+lim] ) 
		res = min( res, minP[fin+lim] ) ;

	printf("%d\n", (res%(1<<30))-1 ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) {
		caso() ;
	}

	return 0 ;
}
