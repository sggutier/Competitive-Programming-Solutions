#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	
	scanf("%d", &N ) ;
	
	if( N>=1 ) 
		printf( "%d\n", (N*(N+1))/2 ) ;
	else
		printf("%d\n", (N*(N+1))/2 +1 ) ;
	
	return 0 ;
}
