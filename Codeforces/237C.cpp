#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 1000006 ;

bool comp[lim] ;

void criba() {
	comp[0] = 1 ;
	comp[1] = 1 ;
	for( int i=2; i*i<lim; i++ )
		if( !comp[i] )
			for( int j=i*i; j<lim; j+=i )
				comp[j] = 1 ;
}

int main() {
	criba() ;

	int A, B, K, carg=0 ;
	int res = -1 ;

	scanf("%d%d%d", &A, &B, &K ) ;

	for( int i=A, j=i; i<=B; i++ ) {
		if( !comp[i] )
			carg ++ ;
		while( carg>K ) 
			carg -= !comp[j++] ;
		while( j<i && comp[j] )
			j ++ ;
		if( carg==K )
			res = max( res, i-j+1 ) ;
	}

	carg = 0 ;
	for( int i=B, j=i; i>=A; i-- ) {
		if( !comp[i] )
			carg ++ ;
		while( carg>K ) 
			carg -= !comp[j--] ;
		while( j>i && comp[j] )
			j -- ;
		if( carg==K )
			res = max( res, j-i+1 ) ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}
