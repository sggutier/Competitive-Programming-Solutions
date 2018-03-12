#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int N, a=0, r=0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	int tmp ;
	scanf("%d", &tmp ) ;
	a += tmp ;
	if( a<0 ) {
	    a = 0 ;
	    r ++ ;
	}
    }

    printf("%d\n", r ) ;
    
    return 0 ;
}
