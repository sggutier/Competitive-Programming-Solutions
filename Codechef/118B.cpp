#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
	int N ;
	int i, j ;
	
	scanf("%d", &N ) ;
	
	for( i=0; i<=N; i++ ) {
		for( j=0; j<N-i; j++ ) 
			printf("  " ) ;
		if( i ) {
			for( j=0; j<=i; j++ ) 
				printf("%d ", j ) ;
			printf("%d", i-1 ) ;
		}
		else 
			printf("0" );
		for( j=i-2; j>=0; j-- ) 
			printf(" %d", j ) ;
		printf("\n" ) ;
	}
	for( i=N-1; i>=0; i-- ) {
		for( j=0; j<N-i; j++ ) 
			printf("  " ) ;
		if( i ) {
			for( j=0; j<=i; j++ ) 
				printf("%d ", j ) ;
			printf("%d", i-1 ) ;
		}
		else 
			printf("0" );
		for( j=i-2; j>=0; j-- ) 
			printf(" %d", j ) ;
		printf("\n" ) ;
	}
	
	return 0 ;
}
