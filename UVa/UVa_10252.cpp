#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

char S[1005], W[1005] ;
int cmnsA[300], cmnsB[300] ;

void caso() {
    int A = strlen(S) ;
    int B = strlen(W) ;

    memset( cmnsA, 0, sizeof(cmnsA) ) ;
    memset( cmnsB, 0, sizeof(cmnsB) ) ;

    for( int i=0; i<A; i++ ) 
	cmnsA[ S[i] ] ++ ;
    for( int i=0; i<B; i++ ) 
	cmnsB[ W[i] ] ++ ;

    for( int i=0; i<300; i++ ) {
	for( int j=min( cmnsA[i], cmnsB[i] ); j; j-- )
	    printf("%c", i ) ;
    }
    printf("\n" ) ;
}

int main() {
    while( gets(S) and gets(W) )
	caso() ;
    
    return 0 ;
}
