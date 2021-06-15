#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

long long mcd( long long a, long long b ) {
	long long c ;
	while( b ) {
		c = b ;
		b = a%b ;
		a = c ;
	}
	return a ;
}

int main() {
	long long a, b ;
	long long x, y ;
	
	cin >> a >> b ;
	
	x = mcd( a, b ) ;
	y = b/x -1;
	x = a/x -1;
	
	if( abs(x-y) == 1 ) 
		cout << "Equal" << endl ;
	else if( x>y ) 
		cout << "Masha" << endl ;
	else 
		cout << "Dasha" << endl ;
		
	return 0 ;
}
