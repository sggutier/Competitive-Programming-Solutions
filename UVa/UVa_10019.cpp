#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

int main() {
    int T ;
    char tmp[505] ;

    gets( (tmp) ) ;
    sscanf( tmp, "%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	int K, a=0 ;
	gets(tmp) ;
	sscanf( tmp, "%d", &K ) ;
	for( int b=31; b>=0; b-- ) {
	    if( (1<<b) & K )
		a ++ ;
	}
	printf("%d ", a ) ;
	a=0 ;
	sscanf( tmp, "%x", &K ) ;
	for( int b=31; b>=0; b-- ) {
	    if( (1<<b) & K )
		a ++ ;
	}
	printf("%d\n", a ) ;
    }
    
    return 0 ;
}
