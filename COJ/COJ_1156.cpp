#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	
	scanf("%d", &N ) ;
	while( N!=42 ) {
		printf("%d\n", N ) ;
		scanf("%d", &N ) ;
	}
	
	return 0 ;
}

