#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		
		if( a==b ) {
			if( a%2 )
				printf("%d\n", b*2-1 ) ;
			else
				printf("%d\n", b*2 ) ;
		}
		else if( a==b+2 ) {
			if( a%2 )
				printf("%d\n", b*2+1 ) ;
			else
				printf("%d\n", b*2+2 ) ;
		}
		else {
			printf("No Number\n" ) ;
		}
	}
	
	return 0 ;
}
