#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	long long a, b, pot ;
	
	cin >> a >> b ;
	
	for( pot = 10LL; pot<=b; pot*=10LL  )  ;
	
	a = max( a, pot/10LL ) ;
	
	pot /= 2LL ;
	
	if( a<=pot && pot<=b )
		a = pot ;
	else if( b-pot < pot-a )
		a = b ;
	pot *= 2LL ;
	
	cout << a*(pot-a-1LL) << endl ;
	
	return 0 ;
}
