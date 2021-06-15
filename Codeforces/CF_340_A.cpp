#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std ;

long long mcd( long long A, long long B ) {
	long long C ;
	while( B ) {
		C = A%B ;
		A = B ;
		B= C ;
	}
	return A ;
}

long long mcm( long long A, long long B ) {
	long long D = mcd( A, B ) ;
	return A/D*B ;
}

int main() {
	long long A, B, X, Y,  C ;

	cin >> A >> B >> X >> Y ;

	C = mcm( A, B ) ;

	cout << (Y/C) - ((X-1)/C) << endl ;

	return 0 ;
}

