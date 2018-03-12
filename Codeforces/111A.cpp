#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	long long n, x, y ;
	
	cin >> n >> x >> y ;
	
	if( n>y || (y-n+1)*(y-n+1)+(n-1) < x )   {
		printf("-1\n" ) ;
		return 0 ;
	}
	
	cout << (y-n+1)  ;
	for( int i=1; i<n; i++ ) 
		printf(" 1" ) ;
	printf("\n" ) ;
	
	return 0 ;
}
