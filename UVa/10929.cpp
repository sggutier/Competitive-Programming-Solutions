#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

int N ;
char S[1005] ;

int main() {
    while( gets(S) && ((N=strlen(S))!=1 || S[0]!='0') ) {
	int a=0, b=a ;
	for( int i=0; i<N; i+=2 )
	    a += S[i]-'0' ;
	for( int i=1; i<N; i+=2 )
	    b += S[i]-'0' ;
	printf("%s is %sa multiple of 11.\n", S, (a%11==b%11)? "":"not " ) ;
    }
    
    return 0 ;
}
