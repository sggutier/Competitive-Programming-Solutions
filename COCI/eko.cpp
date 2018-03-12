#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000006

int N ;
long long arr[lim] ;

long long sum( long long H ) {
	long long res = 0LL ;
	for( int i=0; i<N; i++ ) 
		res += max( 0LL, arr[i]-H ) ;
	return res ;
}

int main() {
	long long W ;
	int a ;
	long long ini, fin, piv ;
	
	cin >> N >> W ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &a ) ;
		arr[i] = 0LL + a ;
	}
	
	ini = 0LL ;
	fin = (1LL<<32) ;
	while( ini<fin ) {
		piv = (ini+fin)/2LL + (ini+fin)%2LL ;
		if( sum(piv)>=W )
			ini = piv ;
		else
			fin = piv-1 ;
	}
	
	cout << ini << endl ;
	
	return 0 ;
}
