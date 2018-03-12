#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	int a=0, b ;
	
	cin >> N ;
	
	b = N/7 ;
	for( int i=0;  i<4 && (N-b*7)%4 && b;  i++, b--  )   ;
	a = (N-b*7)/4  ;
	
	if( a*4 + b*7 ==  N  )  {
		for( int i=0; i<a; i++ )
			printf("4" ) ;
		for( int i=0; i<b; i++ )
			printf("7" ) ;
		printf("\n" ) ;
	}
	else {
		printf("-1\n" ) ;
	}
	
	return 0 ;
}
