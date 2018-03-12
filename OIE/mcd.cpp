#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	long long a, b, c ;
	
	while( scanf("%lld%lld", &a, &b) != EOF    )  {
		while( b ) {
			c = a%b ;
			a = b ;
			b = c ;
		}
		printf("%lld\n", a ) ;
	}
	
	return 0 ;
}

