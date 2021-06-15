#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int N ;
int rep[10000] ;

int main() {
	int res = 0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a ;
		scanf("%d", &a ) ;
		rep[a-1] ++ ;
	}
	
	for( int i=0; i<N; i++ ) {
		if( !rep[i] )
			res ++ ;
	}
	
	printf("%d\n", res) ;

	return 0 ;
}
