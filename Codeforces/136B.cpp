#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;

int A[30], C[30], B[30] ;

void basT( int N, int W[] ) {
	int a = 0 ;
	while( N ) {
		W[a++] = N%3 ;
		N /= 3 ;
	}
}

int main() {
	int X, Y, res=0 ;
	
	cin >> X >> Y ;
	
	basT(X,A) ;
	basT(Y,C) ;
	
	for( int i=0; i<30; i++ ) 
		B[i] = min(  (C[i]+3-A[i])%3,  (C[i]+3-A[i])%3  ) ;
	
	for( int i=0, Y=1; i<20; i++, Y*=3 ) 
		res += Y*B[i] ;
		
	printf("%d\n", res ) ;
	
	return 0 ;
}
