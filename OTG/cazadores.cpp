#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <list>
using namespace std ;
#define limV 1003
#define limN 203

queue <int> Q ;
int minP[limN][limV] ;
list <int> adj[limV] ;

void amp( int ini, int id ) ;



int main() {
	int V, I, B, E ;
	int mir ;
	int bar[limN], igl[limN] ;
	int resA=0, resB=0, res=(1<<30) ;
	
	scanf("%d", &V ) ;
	scanf("%d", &mir ) ;
	scanf("%d", &I ) ;
	mir -- ;
	for( int i=0; i<I; i++ ) {
		scanf("%d", &igl[i] ) ;
		igl[i] -- ;
	}
	scanf("%d", &B ) ;
	for( int i=0; i<B; i++ ) {
		scanf("%d", &bar[i] ) ;
		bar[i] -- ;
	}
	scanf("%d", &E ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a].push_back( b ) ;
		adj[b].push_back( a ) ;
	}
	
	
	for( int i=0; i<I; i++ ) {
		amp( igl[i], i ) ;
	}
	for( int i=0; i<B; i++ ) {
		for( int j=i; j<B; j++ ) {
			int tmp=0, a, b ;
			for( int k=0; k<I; k++ ) {
				a = max( 0,  -minP[k][mir]+minP[k][ bar[i] ]  )   ;   
				b = max( 0,  -minP[k][mir]+minP[k][ bar[j] ]  )   ;
				tmp = max( tmp, min(a,b)   )  ;
			}
			if( tmp<res  )  {
				res = tmp ;
				resA = bar[i] ;
				resB = bar[j] ;
			}
		}
	}
	
	printf("%d %d\n", resA+1, resB+1 ) ;
	
	return 0 ;
}



void amp( int ini, int id ) {
	int pos ;
	list <int> :: iterator it ;
	
	Q.push( ini ) ;
	minP[id][ini] = 1 ;
	while( !Q.empty()  )  {
		pos = Q.front() ;
		Q.pop() ;
		for( it = adj[pos].begin();  it!=adj[pos].end();  it++    )   {
			if( minP[id][*it] )
				continue ;
			 minP[id][*it] = minP[id][pos]+1 ;
			 Q.push( *it ) ;
		}
	}
	
}
