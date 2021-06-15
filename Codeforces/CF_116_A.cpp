#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int N ;
	int res = 0 ;
	
	scanf("%d", &N ) ;
	for( int carg=0; N; N-- ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		carg += b-a ;
		res = max( carg, res ) ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}

