#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

long long calc( long long N, long long k ) {
	long long w = 1LL, res=0LL ; ;
	while( N/w ) {
		res += N/w ;
		w *= k ;
	}
	return res ;
}

int main() {
	long long N, k ;
	long long ini, fin, piv ;
	
	cin >> N >> k ;
	
	ini = 1LL ;
	fin = (1LL<<40) ;
	while( ini<fin ) {
		piv = (ini+fin)/2LL ;
		if( calc(piv,k) >= N )
			fin = piv ;
		else
			ini = piv+1 ;
	}
	
	cout << ini << endl ;
	
	return 0 ;
}
