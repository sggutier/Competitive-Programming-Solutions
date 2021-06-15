#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ; 

bool val( int A[3] ) {
	if( A[0] > 31  ||  A[1] > 12 )
		return 0 ;
	if( A[0] <= 28 ) {
		return 1 ;
	}
	else if( A[1] == 2 ) {
		return A[0] == 29 &&  A[2]%4 == 0 ;
	}
	else if( A[0] < 31 ) {
		return 1 ;
	}
	else if( A[0] == 31 ){ 
		return A[0] != 4   &&  A[0] != 6  &&  A[0] != 9   &&  A[0] != 11  ;
	}
}

bool men( int A[3], int B[3] ) {
	if( B[2]-A[2] != 18 )
		return B[2]-A[2] > 18 ;
	if(  B[1] != A[1]  )
		return B[1] > A[1] ;
	return B[0] >= A[0] ;
}

int main() {
	int D[3], B[3] ; 
	scanf("%d.%d.%d", &D[0], &D[1], &D[2] ) ;
	scanf("%d.%d.%d", &B[0], &B[1], &B[2] ) ;
	sort( B, B+3 ) ;
	
	do {
		if( val( B )  &&  men( B, D )   )  {
			printf("YES\n") ;
			return 0 ;
		}
	} while( next_permutation( B, B+3 )  )  ;
	
	printf("NO\n") ; 
	return 0 ;
}
