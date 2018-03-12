#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N, A, B ;
	int sum=1 ;
	int W ;
	int res[lim] ;
	
	scanf("%d%d%d", &N, &B, &A ) ;
	res[W=0] = 0 ;
	
	if( !A && B ) {
		printf("-1\n" ) ;
		return 0 ;
	}
	
	printf("1" ) ;
	while( A ) {
		sum += sum ;
		printf(" %d", sum ) ;
		A -- ;
		N -- ;
	}
	while( B ) {
		sum ++ ;
		printf(" %d", sum ) ;
		B-- ;
		N -- ;
	}
	while( N ) {
		printf(" 1") ;
		N -- ;
	}
	printf("\n" ) ;
	
	return 0 ;
}


