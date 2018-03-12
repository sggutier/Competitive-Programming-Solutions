#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
#include <utility>
#include <cstring>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
const long long mod = 1000000007LL ;
const long long wtf =  500000004LL ;
const int lim = 200005 ;
const int inf = (1<<30) ;

int N, W=0 ;
list <int> adj[lim] ;
long long carg1[lim], carg2[lim] ;
bool col[lim] ;
long long inv[lim], pot[lim] ;
int prof[lim], pOcur[lim] ;
int padre[lim] ;
par arr[lim*10] ;

void precalc() {
	par mucho = par( (1<<30), 0 ) ;
	pot[0] = 1LL ;
	inv[0] = 1LL ;
	for( int i=1; i<lim; i++ ) {
		inv[i] = (inv[i-1]*wtf)%mod ;
		pot[i] = (pot[i-1]*2LL)%mod ;
	}
	for( int i=0; i<lim*10; i++ )
		arr[i] = mucho ;
}

void mete( int mrk, par val, int pos, int ini, int fin ) {
	if( mrk<ini || mrk>fin )
		return ;
	arr[pos] = min( arr[pos], val ) ;
	if( ini==fin )
		return ;
	int piv = (ini+fin)/2 ;
	mete( mrk, val, pos*2, ini, piv ) ;
	mete( mrk, val, pos*2+1, piv+1, fin ) ;
}

par saca( int a, int b, int pos, int ini, int fin ) {
	if( fin<a || b<ini )
		return par( inf, 0 ) ;
	if( a<=ini && fin<=b )
		return arr[pos] ;

	int piv = (ini+fin)/2 ;
	return min( saca( a, b, pos*2, ini, piv ) , saca( a, b, pos*2+1, piv+1, fin ) ) ;
}

void dfs( int pos, int ant, long long X, long long Y ) {
	padre[pos] = ant ;
	pOcur[pos] = W ;
	if( pos ) {
		prof[pos] = prof[ant]+1 ;
	}

	mete( W++, par(prof[pos],pos), 1, 0, N*2-1 )  ;

	X += (long long)(col[pos]) ;
	Y += (long long)(col[pos])*pot[ prof[pos]-1 ] ;
	X %= mod ;
	Y %= mod ;
	carg1[pos] = X ;
	carg2[pos] = Y ;

	for( list<int>::iterator it=adj[pos].begin(); it!=adj[pos].end(); it++ ) {
		dfs( *it, pos, (X*2LL)%mod, Y ) ;
		mete( W++, par(prof[pos],pos), 1, 0, N*2-1 )  ;
	}
}

int junto( int a, int b ) {
	if( pOcur[a] > pOcur[b] )
		swap( a, b ) ;
	par w = saca( pOcur[a], pOcur[b], 1, 0, N*2-1 ) ;

	return w.s ;
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

		Y = ( carg1[b] +mod - ( (carg1[c]*pot[prof[b]-prof[c]])%mod ) )%mod ;
		X = ( ( (carg2[a]-carg2[c]+mod)%mod )*inv[prof[c]] )%mod ;


		if( col[c] ) {
			Y += pot[prof[b]-prof[c]] ;
			Y %= mod ;
		}

		X = (X*pot[prof[b]-prof[c]+1]+Y)%mod ;

		printf("%lld\n", X ) ;
	}

	return 0 ;
}

