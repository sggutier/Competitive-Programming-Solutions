#include <cstdio>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
    long long N ;

    while( scanf("%lld", &N) && N>=0LL ) 
	printf("%lld\n", (N*(N+1)/2LL) +1LL ) ;
    
    return 0 ;
}
