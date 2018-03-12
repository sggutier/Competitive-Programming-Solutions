#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    char A ;

    while( scanf("%c", &A ) != EOF ) {
	if( A=='\n' )
	    printf("\n" ) ;
	else
	    printf("%c", char((int(A)+249)%256) ) ;
    }
    
    return 0 ;
}
