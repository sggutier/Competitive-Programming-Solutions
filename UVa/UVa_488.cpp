#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

bool fst = 1 ;

void caso() {
    int A, B ;
    scanf("%d%d", &B, &A ) ;
    for( int i=0; i<A; i++ ) {
	if( !fst )
	    printf("\n" ) ;
	fst = 0 ;
	for( int j=1; j<=B; j++ ) {
	    for( int k=0; k<j; k++ )
		printf("%d", j ) ;
	    printf("\n" ) ;
	}
	for( int j=B-1; j>=1; j-- ) {
	    for( int k=0; k<j; k++ )
		printf("%d", j ) ;
	    printf("\n" ) ;
	}
    }
}

int main() {
    int t ;

    scanf("%d", &t ) ;
    for( int i=0; i<t; i++ )
	caso() ;
    return 0 ;
}
