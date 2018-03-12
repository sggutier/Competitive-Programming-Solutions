#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 30003

int main() {
	int N, C ;
	int col[lim] ;
	int rep[] = { 0, 0 } ;
	int i, j ;
	int res = (1<<30) ;
	
	scanf("%d%d", &C, &N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d", &col[i] ) ;
	}
	col[N] = 0 ;
	
	if( C==1 ) {
		printf("0\n" ) ;
		return 0 ;
	}
	
	for( i=0, j=0, rep[ col[0] ]++; i<N;    rep[ col[i] ] --, i++ ) {
		for( ; rep[0]<C; j = (j+1)%N,  rep[ col[j] ] ++   )   ;
		res = min( res, rep[1]  )  ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
