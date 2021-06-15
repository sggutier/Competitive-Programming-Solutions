#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
	int N ;
	int res[1000] ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a ;
		scanf("%d", &a ) ;
		res[a-1] = i+1 ;
	}
	
	for( int i=0; i<N; i++ )
		printf("%d ", res[i] ) ;
	cout << endl ;

	return 0 ;
}
