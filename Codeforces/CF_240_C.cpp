#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	freopen( "input.txt", "r", stdin ) ;
	freopen( "output.txt", "w", stdout ) ;
	
	int N, W, W2 ;
	int A[1000], B[1000] ;
	
	scanf("%d", &N ) ;
	
	if( N==2 ) {
		printf("1\n1 1\n" ) ;
		return 0 ;
	}
	if( N==3 ) {
		printf("2\n1 1\n1 2\n" ) ;
		return 0 ;
	}
	
	W = N/2 + N%2 ;
	W2 = W/2 + W%2 ;
	
	for( int i=0; i<W; i++ )
		A[i] = i+1 ;
	for( int i=0; i<N-W; i++ )
		B[i] = i+W+1 ;
	
	printf("%d\n", 3 ) ;
	printf("%d", W ) ;
	for( int i=0; i<W; i++ )
		printf(" %d", A[i] ) ;
	printf("\n" ) ;
	
	
	return 0 ;
}
