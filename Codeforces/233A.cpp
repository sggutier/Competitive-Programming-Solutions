#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	
	scanf("%d", &N ) ;
	
	if( N%2 ) {
		printf("-1\n" ) ;
		return 0 ;
	}
	
	for( int i=0; i<N; i+=2 ) 
		printf("%d %d ", i+2, i+1 ) ;
	printf("\n" ) ;
	
	return 0 ;
}
