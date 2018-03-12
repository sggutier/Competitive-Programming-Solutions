#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std ;

int main() {
    int N ;
    char tmp[10005] ;
    long long A, B ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	int res = 0 ;
	scanf("%lld", &A) ;
	do {
	    sprintf( tmp, "%lld", A ) ;
	    reverse( tmp, tmp+strlen(tmp) ) ;
	    sscanf( tmp, "%lld", &B ) ;
	    if( A==B ) {
		break ;
	    }
	    A = A+B ;
	    res ++ ;
	} while( 1 )  ;
	printf("%d %lld\n", res, A ) ;
    }
    
    return 0 ;
}
