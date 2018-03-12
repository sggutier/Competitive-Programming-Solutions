#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int n, d ;
	int i, gan ;
	
	scanf("%d%d", &n, &d ) ;
	
	for( i=2, gan=0; i<=n; gan = ( gan + i + d ) % i, i++  )   ;
	
	printf("%d\n", gan+1 ) ;
	
	return 0 ;
}
