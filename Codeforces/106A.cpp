#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std ;

int main() {
	string a, b , c ;
	
	cin >> a >> b >> c ;
	
	if( b[0] == 'T' )
		b[0] = '0' + 10 ;
	else if( b[0] == 'J' )
		b[0] = '0' + 11 ;
	else if( b[0] == 'Q' )
		b[0] = '0' + 12 ;
	else if( b[0] == 'K' )
		b[0] = '0' + 13 ;
	else if( b[0] == 'A' )
		b[0] = '0' + 14 ;
	if( c[0] == 'T' )
		c[0] = '0' + 10 ;
	else if( c[0] == 'J' )
		c[0] = '0' + 11 ;
	else if( c[0] == 'Q' )
		c[0] = '0' + 12 ;
	else if( c[0] == 'K' )
		c[0] = '0' + 13 ;
	else if( c[0] == 'A' )
		c[0] = '0' + 14 ;
		
	if( b[1] == c[1] ) {
		if( b[0] > c[0] )
			printf("YES\n" ) ;
		else
			printf("NO\n" ) ;
		return 0 ;
	}
	
	if( b[1] == a[0] )
			printf("YES\n" ) ;
		else
			printf("NO\n" ) ;
	
	return 0 ;
}
