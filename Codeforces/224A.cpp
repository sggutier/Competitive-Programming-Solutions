#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int A, B, C ;

	scanf("%d%d%d", &A, &B, &C ) ;

	for( int i=1; i<=A; i++ ) {
		int j=A/i, k=B/i, k2=C/i ;

		if( i*j==A && i*k==B && j*k==C ) {
			printf("%d\n", (i+j+k)*4 ) ;
			return 0 ;
		}
		if( i*j==A && i*k2==C && j*k2==B ) {
			printf("%d\n", (i+j+k2)*4 ) ;
			return 0 ;
		}

	}
	return 0 ;
}
