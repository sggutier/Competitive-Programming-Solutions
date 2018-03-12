#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int n, a, b ;
	
	scanf("%d%d%d", &n, &a, &b ) ;
	
	printf("%d\n", max( 0, min(n-a,b+1) )   )  ;
	
	return 0 ;
}
