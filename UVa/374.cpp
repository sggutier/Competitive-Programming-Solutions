#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

long long mod ;

long long pot( long long A, long long B ) {
    if( A==0LL )
	return 1LL ;
    long long res = pot(A/2LL, B) ;
    res = (res*res)%mod ;
    if( A%2 )
	res = (res*B)%mod ;
    return res ;
}

int main() {
    long long A, B ;

    while( scanf("%lld%lld%lld", &B, &A, &mod ) != EOF )
	printf("%lld\n", pot(A,B) ) ;
    
    return 0 ;
}
