#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int a ;
	
	scanf("%d", &a ) ;
	while( a!=42 ) {
		printf("%d\n", a ) ;
		scanf("%d", &a ) ;
	}
	
	return 0 ;
}

