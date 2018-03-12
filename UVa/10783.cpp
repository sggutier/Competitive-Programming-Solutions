#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int res( int A ) {
    if( A<=0 )
	return 0 ;
    A = A/2 + A%2 ;
    return A*A ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=1; i<=T; i++ ) {
	int A, B ;
	scanf("%d%d", &A, &B ) ;
	A-- ;
	printf("Case %d: %d\n", i, res(B)-res(A) ) ;
    }
    
    return 0 ;
}
