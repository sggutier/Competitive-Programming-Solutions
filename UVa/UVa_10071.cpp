#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    long long A, B ;

    while( scanf("%lld%lld", &A, &B ) != EOF ) {
	printf("%lld\n", A*B*2LL ) ;
    }
    
    return 0 ;
}
