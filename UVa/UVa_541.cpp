#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

void caso( int N ) {
    int ren[105],col[105] ;
    int mat[105][105] ;
    int a=0, b=0 ;

    memset( ren, 0, sizeof(ren) ) ;
    memset( col, 0, sizeof(col) ) ;
    for( int i=0; i<N; i++ ) {
	for( int j=0; j<N; j++ ) {
	    scanf("%d", &mat[i][j] ) ;
	    ren[i] += mat[i][j] ;
	    col[j] += mat[i][j] ;
	}
    }

    for( int i=0; i<N; i++ ) {
	if( ren[i]%2 )
	    a ++ ;
	if( col[i]%2 )
	    b ++ ;
    }

    if( a==0 && b==0 ) {
	printf("OK\n" ) ;
	return ;
    }
    else if( a!=1 && b!=1 ) {
	printf("Corrupt\n" ) ;
	return ;
    }

    for( int i=0; i<N; i++ ) {
	if( ren[i]%2==0 )
	    continue;
	for( int j=0; j<N; j++ ) {
	    if( col[j]%2==0 )
		continue ;
	    printf("Change bit (%d,%d)\n", i+1, j+1 ) ;
	    return ;
	}
    }
}
	

int main() {
    int N ;
    while( scanf("%d",&N)!=EOF && N )
	caso(N) ;
    return 0 ;
}
