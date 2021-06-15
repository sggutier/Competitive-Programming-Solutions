#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int ult[lim] ;

int main() {
	int m, a, b, pos ;
	int t ;
	
	scanf("%d%d%d%d", &a, &b, &m, &pos ) ;
	for( t=1; !ult[pos]; t++ ) {
		ult[pos] = t ;
		pos = (pos*a + b)%m ;
	}
	
	printf("%d\n", t-ult[pos] ) ;
	
	return 0 ;
}
