#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int t = 0 ;
    char tmp ;
    while( scanf("%c", &tmp ) != EOF ) {
	if( tmp=='"' ) {
	    if( t )
		printf("''" ) ;
	    else
		printf("``" ) ;
	    t = 1-t ;
	}
	else
	    printf("%c", tmp ) ;
    }
    return 0 ;
}
