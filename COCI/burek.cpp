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
const int lim = 1000006 ;

int X[lim], Y[lim] ;

int main() {
	int N, Q ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int aX = (1<<30), aY=aX, bX=-aX, bY=-aX ;
		for( int j=0; j<3; j++ ) {
			int x, y ;
			scanf("%d%d", &x, &y ) ;
			x++, y++ ;
			aX = min( aX, x ) ;
			bX = max( bX, x ) ;
			aY = min( aY, y ) ;
			bY = max( bY, y ) ;
		}
		X[ aX+1 ] ++ ;
		X[ bX   ] -- ;
		Y[ aY+1 ] ++ ;
		Y[ bY   ] -- ;
	}

	for( int i=1; i<lim; i++ ) {
		X[i] += X[i-1] ;
		Y[i] += Y[i-1] ;
	}

	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
		char S[5], tmp ;
		int w ;
		scanf("%s", S ) ;
		tmp = S[0] ;
		scanf("%s", S ) ;
		scanf("%d", &w ) ;
		if( tmp=='x' )
			printf("%d\n", X[w+1] ) ;
		else
			printf("%d\n", Y[w+1] ) ;
	}

	return 0 ;
}


