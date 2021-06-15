#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
	int N, M, i ;
	
	scanf("%d%d", &N, &M ) ;
	M %= ( (N+1)*N )/2 ;
	
	for( i=1; i<=M; i++ ) {
		M -= i ;
	}
	
	printf("%d\n", M ) ;
	
	return 0 ;
}
