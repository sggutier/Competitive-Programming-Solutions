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
#define par pair<int,int>
#define f first
#define s second

struct sta {
	int pos, uso, val ;
	sta() {
	}
	sta( int _pos, int _uso, int _val ) {
		pos = _pos ;
		uso = _uso ;
		val = _val ;
	}
};

bool operator<( sta A, sta B ) {
	if( A.val != B.val )
		return A.val > B.val ;
	if( A.uso != B.uso )
		return A.uso < B.uso ;
	return A.pos > B.pos ;
}

int N, X, E ;
int adj[105][105], tele[105][105] ;
int minP[105][15] ;
priority_queue <sta> Q ;

void caso() {
	int L, K ;
	sta act, sig ;

	scanf("%d%d%d%d%d", &X, &N, &E, &L, &K ) ;
	N += X ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ )  {
			adj[i][j] = (1<<29) ;
			tele[i][j] = (1<<29) ;
		}
		for( int j=0; j<=K; j++ )
			minP[i][j] = (1<<29) ;
		adj[i][i] = 0 ;
		tele[i][i] = 0 ;
	}
	for( int i=0; i<E; i++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		a--, b-- ;
		tele[a][b] = c ;
		tele[b][a] = c ;
		adj[a][b] = c ;
		adj[b][a] = c ;
	}

	for( int k=0; k<X; k++ ) 
		for( int i=0; i<N; i++ ) 
			for( int j=0; j<N; j++ ) 
				tele[i][j] = min( tele[i][j], tele[i][k] + tele[j][k] ) ;

	minP[N-1][K] = 0 ;
	Q.push( sta( N-1, K, 0 )  ) ;
	while( !Q.empty() ) {
		act = Q.top() ;
		Q.pop() ;

		if( act.val > minP[act.pos][act.uso] )
			continue ;

		if( act.pos==0 ) {
			printf("%d\n", act.val ) ;
			while( !Q.empty() )
				Q.pop() ;
			return ;
		}

		for( int i=0; i<N; i++ ) {
			sig = act ;
			sig.pos = i ;
			sig.val += adj[ act.pos ][ i ] ;
			if( minP[ sig.pos ][ sig.uso ] > sig.val ) {
				Q.push( sig ) ;
				minP[ sig.pos ][ sig.uso ] = sig.val ;
			}
		}

		if( act.uso==0 )
			continue ;

		for( int i=0; i<N; i++ ) {
			if( tele[act.pos][i] > L )
				continue ;
			sig = act ;
			sig.pos = i ;
			sig.uso -- ;
			if( minP[ sig.pos ][ sig.uso ] > sig.val ) {
				Q.push( sig ) ;
				minP[ sig.pos ][ sig.uso ] = sig.val ;
			}
		}
	}

	printf("-1\n" ) ;

	return ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;

	for( int i=0; i<T; i++ )
		caso() ;

	return 0 ;
}


