#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	freopen( "restack.in", "r", stdin ) ;
	freopen( "restack.out", "w", stdout ) ;
	
	int N ;
	int carg=0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		carg += abs(a-b) ;
	}
	
	printf("%d\n", carg/2 ) ;
	
	return 0 ;
}
