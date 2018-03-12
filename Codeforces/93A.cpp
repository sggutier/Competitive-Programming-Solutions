#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int n, m, a, b ;
	
	cin >> n >> m >> a >> b ;
	a--, b-- ;
	
	if( n%m ) {
		if( b==n-1 )
			b = ((n/m)+1) *m -1 ;
		n = ((n/m)+1) *m ;
	}
	
	if( b/m == a/m ) {
		printf("1\n" ) ;
		return 0 ;
	}
	if( a%m == 0 && b%m==m-1 ) {
		printf("1\n" ) ;
		return 0 ;
	}
	if( a%m == 0 || b%m==m-1 ) {
		printf("2\n" ) ;
		return 0 ;
	}
	if(  m-a%m + b%m  ==  m-1  ) {
		printf("2\n" ) ;
		return 0 ;
	}
	if( b/m-a/m == 1 ) {
		printf("2\n" ) ;
		return 0 ;
	}
	
	printf("3\n" ) ;
	
	return 0 ;
}
