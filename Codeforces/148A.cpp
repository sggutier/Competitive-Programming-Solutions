#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

bool usd[lim] ;

int main() {
	int res = 0, a ;
	
	for( int i=0; i<4; i++ ) {
		scanf("%d", &a ) ;
		for( int j=a; j<lim; j+=a )
			usd[j] = 1 ;
	}
	scanf("%d", &a ) ;
	
	for( int i=1; i<=a; i++ )
		if( usd[i] )
			res ++ ;
		
	printf("%d\n", res ) ;
	
	return 0 ;
}
