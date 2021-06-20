#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

char tmp[105][105] ;

int main() {
    int N=0, M=0 ;

    while( gets(tmp[N++]) ) {
	M = max( M, int(strlen(tmp[N-1])) ) ;
    }

    N -= 2 ;
    for( int i=0; i<M; i++ ) {
	for( int j=0; j<=N; j++ ) {
	    if( !tmp[N-j][i] )
		tmp[N-j][i] = ' ' ;
	    printf("%c", tmp[N-j][i] ) ;
	}
	printf("\n" ) ;
    }
    
    return 0 ;
}
