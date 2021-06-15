#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 24*60+100 ;

int carg[lim] ;

int main() {
	int N ;
	int res = 0 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		carg[a*60+b] ++ ;
	}

	for( int i=0; i<lim; i++ )
		res = max( res, carg[i] ) ;

	printf("%d\n", res ) ;

	return 0 ;
}
