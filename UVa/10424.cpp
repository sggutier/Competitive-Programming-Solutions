#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int val( char c ) {
    if( c>='a' && c<='z' )
	return c-'a'+1 ;
    else if( c>='A' && c<='Z' )
	return c-'A'+1 ;
    else
	return 0 ;
}

int main() {
    char A[30000], B[30000] ;

    while( gets(A) ) {
	gets(B) ;
	int x=strlen(A), y=strlen(B) ;
	int sa=0, sb=0 ;
	for( int i=0; i<x; i++ )
	    sa += val(A[i]) ;
	for( int i=0; i<y; i++ )
	    sb += val(B[i]) ;
	sa = sa%9 ;
	sb = sb%9 ;
	if( !sa )
	    sa += 9 ;
	if( !sb )
	    sb += 9 ;
	if( sa<sb )
	    swap( sa, sb ) ;
	printf("%.2lf %%\n", (sb*100.0)/sa ) ;
    }
    
    return 0 ;
}
