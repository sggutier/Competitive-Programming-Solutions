#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std ;

long long mcd( long long a, long long b ) {
	long long c ;
	while( b ) {
		c = a%b ;
		a = b ;
		b = c ;
	}
	return a ;
}

int main() {
	long long a, b ;
	long long x ;

	cin >> a >> b ;

	x = mcd(a,b+1) ;

	cout << x << endl ;

	return 0 ;
}
