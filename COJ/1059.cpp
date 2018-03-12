#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

void caso( int N ) {
	int res = 0, i ;
	
	printf("The parity of ") ;
	for( i=31; i>=0 && ((1<<i) & N)==0; i-- ) ;
	for( ; i>=0; i-- ) {
		if( (1<<i) & N ) {
			res ++ ;
			printf("1" ) ;
		}
		else {
			printf("0" ) ;
		}
	}
	printf(" is %d (mod 2).\n", res ) ;
}

int main() {
	int N ;
	
	scanf("%d", &N ) ;
	while( N ) {
		caso(N) ;
		scanf("%d", &N ) ;
	}
	
	return 0 ;
}
