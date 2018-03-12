#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
#include <utility>
#include <cstring>
using namespace std ;
const long long mod = 1000000007LL ;
const long long wtf =  500000004LL ;
const int lim = 200005 ;

int N ;
list <int> adj[lim] ;
long long carg1[lim], carg2[lim] ;
bool col[lim] ;
long long inv[lim], pot[lim] ;
int prof[lim], pOcur[lim], padre[lim] ;

void precalc() {
	pot[0] = 1LL ;
	inv[0] = 1LL ;
	for( int i=1; i<lim; i++ ) {
		inv[i] = (inv[i-1]*wtf)%mod ;
		pot[i] = (pot[i-1]*2LL)%mod ;
	}
}

void dfs( int pos, int ant, long long X, long long Y ) {
	padre[pos] = ant ;
	if( pos ) {
		prof[pos] = prof[ant]+1 ;
	}

	X += (long long)(col[pos]) ;
	Y += (long long)(col[pos])*pot[ prof[pos]-1 ] ;
	X %= mod ;
	Y %= mod ;
	carg1[pos] = X ;
	carg2[pos] = Y ;

	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		dfs( *it, pos, (X*2LL)%mod, Y ) ;
	}
}

int junto( int a, int b ) {
	while( prof[b]>prof[a] )  {
		b = padre[b] ;
	}
	while( prof[b]<prof[a] )  {
		a = padre[a] ;
	}

	while( a!=b ) {
		a = padre[a] ;
		b = padre[b] ;
	}

	return a ;
}

int main() {
	precalc() ;

	scanf("%d", &N ) ;
	for( int i=1; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a -- ;
		adj[a].push_back(i) ;
		col[i] = b ;
	}

	prof[0] = 1 ;
	dfs( 0, -1, 0LL, 0LL ) ;

	int Q ;
	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
		int a, b, c ;
		long long X, Y ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		c = junto( a, b ) ;

		Y = ( carg1[b] - ( carg1[c]*pot[prof[b]-prof[c]] ) + mod )%mod ;
		X = ( ( (carg2[a]-carg2[c]+mod)%mod )*inv[prof[c]] )%mod ;


		if( col[c] ) {
			Y += pot[prof[b]-prof[c]] ;
			Y %= mod ;
		}

		X = (X*pot[prof[b]-prof[c]+1]+Y)%mod ;

		cout << X << endl ;
	}

	return 0 ;
}

