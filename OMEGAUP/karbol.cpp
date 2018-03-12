#include <cstdio>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std ;
const int lim = 10005 ;
const int limM = 503 ;

int N, C ;
short carg[lim][limM] ;
bool ban[lim][limM] ;
list <short> adj[lim] ;
short color[lim] ;

void busca( int pos ) {
	int W = adj[pos].size() ;
	
	for( list<short>::iterator it = adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		int tmp = *it ;
		busca(tmp) ;
		for( int i=0; i<C; i++ ) 
			if( ban[tmp][i] )
				carg[pos][i] ++ ;
	}
	
	//cout << pos << " -> " ;
	for( int i=0; i<C; i++ ) {
		if( carg[pos][i]!=W )
			ban[pos][i] = 1 ;
	}
	
	/*for( int i=0; i<C; i++ )
		if( !ban[pos][i] ) 
			printf("%d ", i ) ;
	printf("\n" ) ;*/
}

void colorea( int pos, int ant ) {
	
	for( int i=0; i<C; i++ ) {
		if( i!=ant && !ban[pos][i] ) {
			color[pos] = i ;
			break ;
		}
	}
	
	for( list<short>::iterator it = adj[pos].begin(); it!=adj[pos].end(); it++ ) 
		colorea( *it, color[pos] ) ;
}

int main() {
	int Q ;
	
	scanf("%d%d", &N, &C ) ;
	color[0] = -1 ;
	for( int i=1; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		adj[tmp].push_back(i) ;
	}
	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		ban[a][b] = 1 ;
	}
	
	
	busca(0) ;
	colorea( 0, -1 ) ;
	
	if( color[0]==-1 ) {
		printf("%d\n", color[0] ) ;
		return 0 ;
	}
	
	for( int i=0; i<N; i++ )
		printf("%d\n", color[i] ) ;
	
	return 0 ;
}
