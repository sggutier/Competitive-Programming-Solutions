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
const int lim = 305 ;
const int inf = (1<<28) ;
typedef pair<int,int> par ;
#define f first
#define s second

int N, H, K ;
list <par> adj[lim] ;
int son[lim], dPar[lim], bro[lim] ;
int minL[lim][lim][2] ;
bool fed[lim][lim][2] ;

void reset() {
	memset( fed, 0, sizeof(fed) ) ;
	memset( dPar, 0, sizeof(dPar) ) ;
	for( int i=0; i<N; i++ ) { 
		adj[i].clear() ;
		bro[i] = son[i] = -1 ;
	}
}

void chngPOV( int pos, int parent ) {
	int last = -1 ;
	for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end();  it++  ) {
		if( it->s == parent )
			continue ;
		dPar[it->s] = it->f ;
		if( last==-1 ) 
			son[pos] = it->s ;
		else 
			bro[last] = it->s ;
		last = it->s ;
		chngPOV( last, pos ) ;
	}
}

int memo2( int d, int rem, int colP ) {
	if( d<0 ) {
		if( rem==0 )
			return 0 ;
		else
			return inf ;
	}

	if( fed[d][rem][colP] )
		return minL[d][rem][colP] ;

	fed[d][rem][colP] = 1 ;
	minL[d][rem][colP] = inf ;

	for( int b=0; b<2; b++ ) {
		for( int i=rem-b; i>=0; i-- ) {
			int j=rem-b-i ;

			if( b==colP )
				minL[d][rem][colP] = min( minL[d][rem][colP], memo2( bro[d], i, colP ) + memo2( son[d], j, b ) + dPar[d] ) ;
			else
				minL[d][rem][colP] = min( minL[d][rem][colP], memo2( bro[d], i, colP ) + memo2( son[d], j, b )  ) ;
		}
	}

	return minL[d][rem][colP] ;
}

int memo3( int d, int rem, int colP ) {
	if( d<0 ) {
		if( rem==0 )
			return 0 ;
		else
			return inf ;
	}

	if( fed[d][rem][colP] )
		return minL[d][rem][colP] ;

	fed[d][rem][colP] = 1 ;
	minL[d][rem][colP] = inf ;

	for( int b=0; b<2; b++ ) {
		for( int i=rem-b; i>=0; i-- ) {
			int j=rem-b-i ;

			if( b==colP && colP==1 )
				minL[d][rem][colP] = min( minL[d][rem][colP], memo3( bro[d], i, colP ) + memo3( son[d], j, b ) + dPar[d] ) ;
			else
				minL[d][rem][colP] = min( minL[d][rem][colP], memo3( bro[d], i, colP ) + memo3( son[d], j, b )  ) ;
		}
	}

	return minL[d][rem][colP] ;
}

void test_case() {
	scanf("%d%d%d", &N, &H, &K ) ;
	reset() ;
	for( int i=1; i<N; i++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b-- ;
		adj[a].push_back( par(c,b) ) ;
		adj[b].push_back( par(c,a) ) ;
	}

	if( H-1+K > N ) {
		printf("-1\n") ;
		return ;
	}

	chngPOV( 0, 0 ) ;

	if( H==2 )
		printf("%d\n", memo2(son[0],K-1,1) ) ;
	else
		printf("%d\n", memo3(son[0],K-1,1) ) ;
}

int main() {
	for( int i=0; i<10; i++ ) 
		test_case() ;

	return 0 ;
}


