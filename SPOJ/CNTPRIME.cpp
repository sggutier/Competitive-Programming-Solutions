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
const int limP = 1000006 ;
const int limN = 10006 ;

int N ;
int arr[limN*10] ;
bool usd[limP] ;
int crg[limN*10] ;

void criba() {
	usd[0] = 1 ;
	usd[1] = 1 ;
	for( int i=2; i*i<limP; i++ ) {
		if( usd[i] )
			continue ;
		for( int j=i*i; j<limP; j+=i )
			usd[j] = 1 ;
	}
}

void cmb( int ini, int fin, int A, int B, int pos ) {
	if( ini==A && fin==B ) {
		int tmp = 0, w=0 ;
		crg[pos] = (crg[pos]+1)%2 ;
		tmp -= arr[pos] ;
		arr[pos] = (B-A+1) - arr[pos] ;
		tmp += arr[pos] ;
		pos /= 2 ;
		while( pos ) {
		    w += crg[pos] ;
		    if( w%2 )
                arr[pos] -= tmp ;
            else
                arr[pos] += tmp ;
			pos /= 2 ;
		}
		return ;
	}
	int piv = (ini+fin)/2 ;

	if( B<=piv )
		cmb( ini, piv, A, B, pos*2 ) ;
	else if( A>piv )
		cmb( piv+1, fin, A, B, pos*2 +1 ) ;
	else {
		cmb( ini, piv, A, piv, pos*2 ) ;
		cmb( piv+1, fin, piv+1, B, pos*2+1 ) ;
	}
}

int carg( int ini, int fin, int A, int B, int pos, int K ) {
	if( ini==A && fin==B ) {
		if( K%2 )
			return (B-A+1)-arr[pos] ;
		else
			return arr[pos] ;
	}
	int piv = (ini+fin)/2 ;

	if( B<=piv )
		return carg( ini, piv, A, B, pos*2, K+crg[pos] ) ;
	else if( A>piv )
		return carg( piv+1, fin, A, B, pos*2 +1, K+crg[pos] ) ;
	else {
		return carg( ini, piv, A, piv, pos*2, K+crg[pos] ) + carg( piv+1, fin, piv+1, B, pos*2+1, K+crg[pos] ) ;
	}
}

void caso() {
	int Q ;

	memset( crg, 0, sizeof(crg) ) ;
	memset( arr, 0, sizeof(arr) ) ;

	scanf("%d%d", &N, &Q ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		tmp = !usd[tmp] ;
		mete( 1, 0, N-1, i, i, tmp ) ;
	}

	for( int i=0; i<Q; i++ ) {
		int t, x, y, z ;
		scanf("%d%d%d", &t, &x, &y ) ;
		if( t ) {
			printf("%d\n", saca(1,0,N-1,x-1,y-1)  ) ;
		}
		else {
			scanf("%d", &z ) ;
			mete( 1, 0, N-1, x-1, y-1, !usd[z] ) ;
		}
	}
}

int main() {
	criba() ;

	int T ;

	scanf("%d", &T  );

	for( int i=0; i<T; i++ ) {
		printf("Case %d:\n", i+1 ) ;
		caso() ;
	}

	return 0 ;
}


