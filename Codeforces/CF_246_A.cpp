#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
	int N ;

	scanf("%d", &N ) ;

	if( N<=2 ) {
		printf("-1\n" ) ;
		return 0 ;
	}

	for( int i=0; i<N; i++ ) 
		printf("%d ", (i+1)%N +1 ) ;
	printf("\n" ) ;

	return 0 ;
}
