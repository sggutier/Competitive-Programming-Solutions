#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std ;

int mcd( int a, int b ) {
	int c ;
	while( b ) {
		c = a%b ;
		a = b ;
		b = c ;
	}

	return a ;
}

int main() {
	int N ;
	int g1, g2, a, b, c ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d%d%d", &g1, &g2, &a, &b ) ;
		c = mcd( a, b ) ;
		printf("%d", abs(g1-g2)%c==0 ) ;
	}
	printf("\n" ) ;

	return 0 ;
}
