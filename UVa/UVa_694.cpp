#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    long long A, B ;
    int T=1, s ;

    while( scanf("%lld%lld", &A, &B)!=EOF && A>0 && B>0 ) {
	s = 0 ;
	long long tmp = A ;
	while( A>1 && A<=B ) {
	    if( A%2 )
		A = A*3 +1 ;
	    else
		A /= 2 ;
	    s ++ ;
	}
	if( A<=B )
	    s ++ ;
	printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n" , T++, tmp, B, s ) ;
    }
    
    return 0 ;
}
