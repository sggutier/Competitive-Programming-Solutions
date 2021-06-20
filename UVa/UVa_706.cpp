#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

bool led[10][7] = { {1, 1, 1, 1, 1, 1, 0},
		    {0, 1, 1, 0, 0, 0, 0},
		    {1, 1, 0, 1, 1, 0, 1},
		    {1, 1, 1, 1, 0, 0, 1},
		    {0, 1, 1, 0, 0, 1, 1},
		    {1, 0, 1, 1, 0, 1, 1},
		    {1, 0, 1, 1, 1, 1, 1},
		    {1, 1, 1, 0, 0, 0, 0},
		    {1, 1, 1, 1, 1, 1, 1},
		    {1, 1, 1, 1, 0, 1, 1} } ;

int T, N ;
char tmp[15] ;

void caso() {
    N = strlen(tmp) ;
    for( int i=0; i<N; i++ )
	tmp[i] -= '0' ;
    
    for( int i=0; i<N; i++ ) {
	if( i )
	    printf(" " ) ;
	printf(" " ) ;
	for( int j=0; j<T; j++ ) 
	    printf("%c", led[tmp[i]][0]? '-':' ' ) ;
	printf(" " ) ;
    }
    printf("\n" ) ;

    for( int k=0; k<T; k++ ) {
	for( int i=0; i<N; i++ ) {
	    if( i )
		printf(" " ) ;
	    printf("%c", led[tmp[i]][5]? '|':' ' ) ;
	    for( int j=0; j<T; j++ ) 
		printf(" ") ;
	    printf("%c", led[tmp[i]][1]? '|':' ' ) ;
	}
	printf("\n" ) ;
    }

    for( int i=0; i<N; i++ ) {
	if( i )
	    printf(" " ) ;
	printf(" " ) ;
	for( int j=0; j<T; j++ ) 
	    printf("%c", led[tmp[i]][6]? '-':' ' ) ;
	printf(" " ) ;
    }
    printf("\n" ) ;

    for( int k=0; k<T; k++ ) {
	for( int i=0; i<N; i++ ) {
	    if( i )
		printf(" " ) ;
	    printf("%c", led[tmp[i]][4]? '|':' ' ) ;
	    for( int j=0; j<T; j++ ) 
		printf(" ") ;
	    printf("%c", led[tmp[i]][2]? '|':' ' ) ;
	}
	printf("\n" ) ;
    }

    for( int i=0; i<N; i++ ) {
	if( i )
	    printf(" " ) ;
	printf(" " ) ;
	for( int j=0; j<T; j++ ) 
	    printf("%c", led[tmp[i]][3]? '-':' ' ) ;
	printf(" " ) ;
    }
    printf("\n\n" ) ;
}

int main() {
    bool fst = 0 ;
    while( scanf("%d%s", &T, tmp) != EOF && T ) {
	fst = 1 ;
	caso() ;
    }
    return 0 ;
}
