#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <queue>
#include <utility>
using namespace std ;
#define lim 10005

int maxH[lim] ;

int main() {
	int a, b, c ;
	
	while( scanf("%d%d%d", &a, &b, &c ) != EOF   )   {
		while( a<c ) {
			maxH[a] = max( maxH[a], b ) ;
			a ++ ;
		}
	}
	
	a = 0 ;
	for( int i=1; i<lim; i++ ) {
		if( maxH[i] != maxH[i-1] ) {
			if( a )
				printf(" " ) ;
			printf("%d %d", i, maxH[i] ) ;
			a = 1 ;
		}
	}
	printf("\n" ) ;
	
	return 0 ;
}
