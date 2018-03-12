#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

long long nenk( int n, int k ) {
	if( k>n || k<0 )
		return 0LL ;
	
	k = max( k, n-k ) ;
	long long res = 1LL, i ;
	
	for( i=n+0LL; i>k; i-- )
		res *= i;
	for( i=n-k+0LL; i; i-- )
		res /= i ;
		
	return res ;
}

int main() {
	int n, k, w ;
	
	cin >> n ;
	
	if( n<4 ) {
		cout << 0 << endl ;
		return 0 ;
	}
	
	if( n%2 ) {
		cout << 0 << endl ;
		return 0 ;
	}
	
	w = (n-4)/2 ;
	k = n-w-1 ;
	cout << nenk( k, w ) + 2*nenk( k, w-1 )  << endl ;
	
	return 0 ;
}
