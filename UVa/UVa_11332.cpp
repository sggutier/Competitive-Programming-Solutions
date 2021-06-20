#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    long long K ;

    while( scanf("%lld",&K)!=EOF && K ) {
	printf("%lld\n", (K%9)? K%9 : 9LL ) ;
    }
    
    return 0 ;
}
