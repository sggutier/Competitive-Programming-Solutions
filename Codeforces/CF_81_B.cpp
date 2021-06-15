#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std ;
#define lim 300

int main() {
	char S[lim] ;
	int N ; 
	int i, j ; 
	char ant = 'A' ;
	
	gets( S ) ;
	N = strlen(S) ; 
	
	for( i=0; i<N; i++ ) {
		if( S[i] == '.' ) {
			if( ant != 'A' )
				printf( " " ) ;
			printf( "..." ) ;
			i += 2 ;
			ant = '.' ;
		}
		else if( S[i] == ',' ) {
			if( ant == ',' )
				printf( " " ) ; 
			printf( "," ) ;
			ant = ',' ;
		}
		else if( S[i] != ' ' ) {
			if( ant==','  ||  ant=='0' )
				printf( " " ) ;
			for( ; i<N && S[i]>='0' && S[i] <='9'; i++ ) 
				printf( "%c", S[i] ) ;
			i -- ;
			ant = '0' ;
		}
	}
	printf( "\n" ) ;
	
	return 0 ; 
}
