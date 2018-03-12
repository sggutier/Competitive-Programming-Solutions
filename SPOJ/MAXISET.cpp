#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 21 ;
const int LIM = 40 ;
const int potLim = (1<<lim) ;

int N, K, bK ;
long long adj[LIM] ;
int arr[LIM] ;
int mWt[potLim] ;
int res ;

void busca( long long msk, int pos, int crg ) {
	if( pos==K ) {
		mWt[msk] = crg ;
		return ;
	}

	if( (1LL<<pos) & msk ) {
		busca( msk & adj[pos], pos+1, crg+arr[pos] ) ;
		busca( msk-(1LL<<pos), pos+1, crg ) ;
	}
	else
		busca( msk, pos+1, crg ) ;
}

void busca2( long long msk, int pos, int crg ) {
	if( pos==N ) {
		res = max( res, crg + mWt[msk%bK] ) ;
		return ;
	}

	if( (1LL<<pos) & msk ) {
		busca2( msk & adj[pos], pos+1, crg+arr[pos] ) ;
		busca2( msk-(1LL<<pos), pos+1, crg ) ;
	}
	else
		busca2( msk, pos+1, crg ) ;
}

void caso(bool frst) {
	int E, Q ;
	int a, b ;
	long long carg = 0 ;
	int W = 1 ;

	memset( mWt, 0, sizeof(mWt) ) ;

	if( !frst )
		printf("\n" ) ;

	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<N; i++ )  {
		scanf("%d", &arr[i] ) ;
		adj[i] = (1LL<<N)-1 ;
	}
	for( int i=0; i<E; i++ ) {
		scanf("%d%d", &a, &b ) ;
		if( !(adj[a] & (1LL<<b)) )
			continue ;
		adj[a] -= (1LL<<b) ;
		adj[b] -= (1LL<<a) ;
	}

	if( N>25 ) {
	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
		scanf("%d", &E ) ;
		int tmp ;
		for( int i=0; i<E; i++ ) {
			scanf("%d", &tmp );
		}
		printf("%d\n", 0 ) ;
	}
		return ;
	}

	K = min( lim, N ) ;
	bK = (1<<K) ;
	busca( bK-1LL, 0, 0 ) ;
	
	for( int i=0; i<bK; i++ ) {
		if( i==(1<<W) )
			W ++ ;
		for( int b=0; b<W; b++ )
			if( (1<<b)&i )
				mWt[i] = max( mWt[i], mWt[i-(1<<b)] ) ;
	}

	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
		int tmp ;
		long long msk = 0LL ;
		res = 0 ;
		scanf("%d", &E ) ;
		for( int i=0; i<E; i++ ) {
			scanf("%d", &tmp );
			msk += (1LL<<tmp) ;
		}
		busca2( msk, K, 0 ) ;
		printf("%d\n", res ) ;
	}
}

int main() {
	int N ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		caso(i==0) ;

	return 0 ;
}
