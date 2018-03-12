#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

int main() {
    long long A, B ;
    
    while( scanf("%lld%lld", &A, &B ) && (A!=0LL || B!=0LL)  ) {
	int res = 0, crg=0 ;
	while( A || B ) {
	    if( A%10 + B%10 + crg>=10  ) {
		crg = 1 ;
		res ++ ;
	    }
	    else
		crg = 0 ;
	    A /= 10 ;
	    B /= 10 ;
	}
	if( res==0  )
	    printf("No carry operation.\n" ) ;
	else if( res!=1 ) 
	    printf("%d carry operations.\n", res ) ;
	else
	    printf("1 carry operation.\n" ) ;
    }
    
    return 0 ;
}
