#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

void  caso(long long cig, long long K) {
    long long res = 0LL ;
    long long col = 0LL ;
    while( cig ) {
	res += cig ;
	col += cig ;
	cig = col/K ;
	col %= K ;
    }
    printf("%lld\n", res ) ;
}
	

int main() {
    long long A, B ;

    while( scanf("%lld%lld", &A, &B) != EOF ) {
	caso( A, B ) ;
    }
    
    return 0 ;
}
