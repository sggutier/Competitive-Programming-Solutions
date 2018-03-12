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
const int lim = 1505 ;

int N, mod ;
char init[lim] ;

void mult( char A[], char B[], char C[] ) {
	for( int i=0; i<mod; i++ )
		C[i] = 0 ;
	for( int i=0; i<mod; i++ )
		for( int j=0; j<mod; j++ )
			if( A[i] && B[j] )
				C[ (i*j)%mod ] = 1 ;
}

void exp( long long K, char res[] ) {
	if( K==1LL ) {
		for( int i=0; i<mod; i++ )
			res[i] = init[i] ;
		return ;
	}

	char tmp[lim] ;

	exp( K/2LL, tmp ) ;
	mult( tmp, tmp, res ) ;
	if( K%2LL ) {
		for( int i=0; i<mod; i++ )
			tmp[i] = res[i] ;
		mult( tmp, init, res ) ;
	}
}

int main() {
	char res[lim] ;
	long long K ;
	memset( res, 0, sizeof(res)  ) ;

	scanf("%lld%d%d", &K, &mod, &N ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		init[tmp] = 1 ;
	}

	exp( K, res ) ;

	for( int i=0; i<mod; i++ ) 
		if( res[i] )
			printf("%d ", i ) ;
	printf("\n" ) ;

	return 0 ;
}

