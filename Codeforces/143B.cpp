#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 1000

char S[lim] ;

int main() {
	int i, N ;
	int sig = 0 ;
	
	gets(S) ;
	N = strlen(S) ;
	
	for( i=0; i<N && S[i]!='.'; i++ ) ;
	if( i+2>=N ) {
		S[i] = '.' ;
		if( !S[i+1] )
			S[i+1] = '0' ;
		if( !S[i+2] )
			S[i+2] = '0' ;
	}
	N = i+3 ;
	
	i = 0 ;
	if( S[i]=='-' ) {
		sig = 1 ;
		printf("(") ;
		i ++ ;
	}
	printf("$" );
	for( ; i<N; i++ ) {
		if( i>sig && i+3<N && (N-i)%3==0 ) 
			printf(",") ;
		printf("%c", S[i] ) ;
	}
	if( sig )
		printf(")") ;
	printf("\n" ) ;
	
	return 0 ;
}

