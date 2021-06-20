#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

bool letra( char A ) {
    return (A>='A' && A<='Z' ) || (A>='a' && A<='z') ; 
} 

int main() {
    char S[100005] ;

    while( gets(S) ) {
	int N = strlen(S), wds=0 ;
	char ult = '\n' ;
	for( int i=0; i<N; i++ ) {
	    if( (letra(S[i]) && !letra(ult) ) )
		wds ++ ;
	    ult = S[i] ;
	}
	printf("%d\n", wds ) ;
    }
    
    return 0 ;
}
