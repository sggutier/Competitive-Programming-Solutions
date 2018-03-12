#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int N ;

    scanf("%d", &N) ;
    for( int i=0; i<N; i++ ) {
	int a, b ;
	scanf("%d%d", &a,&b ) ;
	if( a<b ) 
	    printf("<\n" ) ;
	else if( a>b )
	    printf(">\n" ) ;
	else
	    printf("=\n" ) ;
    }
    
    return 0 ;
}
