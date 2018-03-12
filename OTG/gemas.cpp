#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int N ;
	int rep[4] = { 0, 0, 0, 0 } ;
	int a ;
	
	scanf("%d", &N ) ;
	N*= 2 ;
	while( N ) {
		scanf("%d", &a ) ;
		rep[a] ++ ;
		N -- ;
	}
	
	printf("%d\n", rep[1]/4 + rep[2]/4 + rep[3] / 4 ) ;
	
	return 0 ;
}
