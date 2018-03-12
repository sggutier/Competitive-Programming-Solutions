#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 10007

int main() {
	char S[lim] ;
	int ab[lim], A=0 ;
	int N = 0 ;
	
	gets( S ) ;
	N = strlen( S ) ;
	for( int i=0; i<N; i++ ) {
		if( S[i] == '(' )
			ab[ A++ ] = i ;
		else if( S[i] == ')' ){
			A -- ;
			reverse( S+ab[ A ], S+i ) ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		if( S[i] != '(' && S[i] != ')' )
			printf("%c", S[i] ) ;
	}
	
	return 0 ;
}
