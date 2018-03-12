#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int bit[lim] ;

void mete( int pos, int nov ) {
	for( ; pos<lim; pos += (pos&-pos)   )
		bit[pos] += nov ;
}

int carg( int pos ) {
	int res = 0 ;
	for( ; pos; pos -= (pos&-pos)  ) 
		res += bit[pos] ;
	return res ;
}

int res[lim] ;

int main() {
	int N, A ;
	int ini, fin, piv ;
	
	mete( 1, 1 ) ;
	for( int i=2; i<lim; i++ ) {
		if( i%2 )
			mete( res[i/2]+1, -1 ) ;
		ini = 1 ;
		fin = lim-1 ;
		while( ini<fin ) {
			piv = (ini+fin)/2 ;
			if( carg(piv)!=piv )
				fin = piv ;
			else
				ini = piv+1 ;
		}
		res[i] = ini-1 ;
		mete( ini, 1 ) ;
	}
	
	scanf("%d%d", &N, &A ) ;
	
	for( int i=1; i<=A; i++ ) {
		if( res[i] == res[N] )
			printf("%d ", i ) ;
	}
	printf("\n" ) ;
	
	return 0 ;
}
