#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <utility>
using namespace std ;
#define limN 1007
#define limK 105

int N, K ;
int gana[limN][limK] ;
int minC[limN], cap[limN] ;
list <int> adj[limN] ;
int res[limN][limK] ;

void busca( int pos, int padre ) ;

int main() {
	int i, j ;
	int a, b ;
	
	scanf("%d%d",&N,&K ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d%d",&minC[i],&cap[i] ) ;
	}
	for( i=0; i<N; i++ ) {
		for( j=1; j<=cap[i]; j++ ) 
			scanf("%d", &gana[i][j] ) ;
		for( j=0; j<minC[i]; j++ ) 
			gana[i][j] = 0 ;
		for( j=cap[i]+1; j<=K; j++ )
			gana[i][j] = gana[i][j-1] ;
	}
	for( i=1; i<N; i++ ) {
		scanf("%d%d",&a,&b ) ;
		a--, b-- ;
		adj[a].push_back( b ) ;
		adj[b].push_back( a ) ;
	}
	
	busca(0,-1) ;
	
	cout << res[0][K] << endl ;
	
	return 0 ;
}


void busca( int pos, int padre ) {
	if( minC[pos]>cap[pos] ) 
		return ;
		
	int Q = minC[pos] ;
	int i, j, pos2 ;
	for( i=0; i<=K; i++ ) {
		res[pos][i] = gana[pos][i] ;
	}
	list <int> :: iterator  it ;
	
	for( it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		if( (*it) == padre  ) 
			continue ;
		pos2 = (*it) ;
		busca(pos2, pos ) ;
		
		for( i=K-Q; i>=0; i-- ) {
			for( j=1; i+Q+j<=K; j++ ) {
				res[pos][i+Q+j] = max( res[pos][i+Q+j],  res[pos][i+Q] + res[pos2][j]  )  ;
			}
		}
	}
}
