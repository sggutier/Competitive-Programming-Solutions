#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std ;

long long invMCD( long long A, long long B ) {
	long long C ;
	long long X, Y, Z ;
	long long K, W=B, V=A ;

	X = 0LL ;
	Y = 1LL ;

	while( B ) {
		K = A/B ;
		C = A%B ;
		A = B ;
		B = C ;
		Z = Y - (X*K)%W +W ;
		Y = X ;
		X = Z%W ;
	}

	V /= A ;
	W /= A ;
	if( A != 1 )
		return -1LL ;

	return Y%W ;
}

int main() {
	long long A, B ;

	cin >> A >> B ;

	cout << invMCD(A,B) << endl ;

	return 0 ;
}
