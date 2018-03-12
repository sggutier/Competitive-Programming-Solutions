#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 1000006 ;

bool esPrimo( long long foo ) {
	for( int i=2; i*i<=foo; i++ ) {
		if( foo%i==0LL )
			return 0 ;
	}
	return 1 ;
}

long long cuenta( long long W, long long K ) {
	if( !esPrimo(K) )
		return 0LL ;

	W /= K ;
	long long res = W, N=min(W+1,K) ;

	for( int i=2; i<N; i++ ) 
		res -= cuenta(W,i) ;

	return res ;
}

int main() {
	long long A, B, K ;

	cin >> A >> B >> K ;

	A -- ;
	cout << cuenta(B,K)-cuenta(A,K) << endl ;

	return 0 ;
}


