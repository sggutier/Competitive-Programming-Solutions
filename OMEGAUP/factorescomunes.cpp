#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;

long long mcd( long long A, long long B ) {
	long long C ;

	while( B ) {
		C = A%B ;
		A = B ;
		B = C ;
	}

	return A ;
}

int main() {
	long long A, B ;
	int W=1, res=1 ;

	cin >> A >> B ;

	A = mcd( A, B ) ;

	while( A%2==0LL ) {
		W ++ ;
		A /= 2LL ;
	}

	B = sqrt(A) ;
	if( B*B==A && B>1 ) 
		res ++ ;
	if( A>1 )
		res ++ ;

	B -- ;
	if( B%2==0 )
		B -- ;
	for( int i=B; i>1; i-=2 ) {
		if( A%i==0LL ) {
			res += 2 ;
		}
	}

	printf("%d\n", res*W ) ;

	return 0 ;
}
