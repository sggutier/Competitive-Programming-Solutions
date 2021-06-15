#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int n ;
	int R=0 ;
	int resA[100000], resB[100000] ;
	
	scanf("%d", &n ) ;
	
	for( int i=2; i<=n; i++ ) {
		resA[R] = i ;
		resB[R] = i-1 ;
		R ++ ;
		for( int j=i-3; j>0; j-=2 ) {
			resA[R] = i ;
			resB[R] = j ;
			R ++ ;
		}
	}
	
	printf("%d\n", R );
	for( int i=0; i<R; i++ ) {
		printf("%d %d\n", resA[i], resB[i] ) ;
	}
	
	return 0 ;
}
