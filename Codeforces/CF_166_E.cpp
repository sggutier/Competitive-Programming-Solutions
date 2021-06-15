#include <iostream>
using namespace std ;
#define mod 1000000007LL

int main() {
	long long a=1LL, b=0LL ;
	long long x, y ;
	int N ;
	
	cin >> N ;
	
	for( int i=0; i<N; i++ ) {
		x = 3LL*b ;
		y = 2LL*b + a ;
		a = x%mod ;
		b = y%mod ;
	}
	
	cout << a << endl ;
	
	return 0 ;
}
