#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;

long long mcd( long long A, long long B, long long &lastY ) {
	long long C, Y, Q ;
	lastY = 0LL ;
	Y = 1LL ;
	while( B ) {
		C = A%B ;
		Q = A/B ;
		A = B ;
		B = C ;
		
		C = Y ;
		Y = lastY-Q*Y ;
		lastY = C ;
	}
	return A ;
}

int main() {
	long long a, b, c ;
	long long w, m, n ;
	long long g ;
	long long x, y ;
	
	cin >> a >> b >> c ;
	
	if( !b ) {
		if( c%a==0LL ) 
			cout << 0 << " " << -c/a << endl ;
		else
			cout << -1 << endl ;
		return 0 ;
	}
	
	w = ( b-(c%b)) %b ;
	m = mcd( a, b, n ) ;
	if( w%m ) {
		cout << -1 << endl ;
		return 0 ;
	}
	w = w/m ;
	n = b/m ;
	m = a/m ;
	mcd( n, m, g ) ;
	x = (g*w)%n ;
	y = -(a*x+c)/b ;
	
	cout << x << " " <<  y << endl; 
	
	return 0 ;
}
