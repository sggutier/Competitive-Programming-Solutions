#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

bool bouncy( int N ) {
	int X, a, b ;
	
	X = N ;
	a = 10 ;
	while( X ) {
		b = X%10 ;
		if( a<b )
			break ;
		X /= 10 ;
		a = b ;
	}
	
	if( X==0 )
		return 0 ;
	
	X = N ;
	a = 0 ;
	while( X ) {
		b = X%10 ;
		if( a>b )
			break ;
		X /= 10 ;
		a = b ;
	}
	
	return X!=0 ;
}

int main() {
	int N ;
	int a=0, b=0 ;
	
	cin >> N ;
	
	do {
		b ++ ;
		if( bouncy(b) )
			a ++ ;
		printf("%d %d\n", a, b ) ;
		getchar() ;
	}while( a*100 != N*b ) ;
	
	cout << b << endl ;
	
	return 0 ;
}
