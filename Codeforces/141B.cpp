#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int a, x, y ;
	
	cin >> a >> x >> y ;
	
	if( y%a==0 ) {
		printf("-1\n" ) ;
		return 0 ;
	}
	if( y<a ) {
		if( abs(x)< (a/2)+(a%2)  ) 
			printf("1\n" ) ;
		else
			printf("-1\n" ) ;
		return 0 ;
	}
	
	y -= a ;
	if( y%(2*a)>a ) {
		if( abs(x)<a ) {
			if( x<0 ) 
				printf("%d\n", (y/(2*a))*3 + 3 ) ;
			else if( x>0 )
				printf("%d\n", (y/(2*a))*3 + 4 ) ;
			else
				printf("-1\n" ) ;
		}
		else
			printf("-1\n" ) ;
	}	
	else {
		if( abs(x)< (a/2)+(a%2)  ) 
			printf("%d\n", (y/(2*a))*3 + 2 ) ;
		else
			printf("-1\n" ) ;
	}
	
	return 0 ;
}

