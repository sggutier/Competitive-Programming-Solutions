#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

void caso( int R, int C ) {
    char S[105][105] ;
    int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 } ;
    int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 } ;

    for( int i=0; i<R; i++ ) {
	scanf("%s", S[i] ) ;
	for( int j=0; j<C; j++ ) {
	    if( S[i][j]=='.' )
		S[i][j] = '0' ;
	}
    }

    for( int i=0; i<R; i++ ) {
	for( int j=0; j<C; j++ ) {
	    if( S[i][j]!='*' )
		continue ;
	    for( int d=0; d<8; d++ ) {
		int x=i+dr[d], y=j+dc[d] ;
		if( x<0 || x>=R || y<0 || y>=C || S[x][y]=='*' )
		    continue ;
		S[x][y] ++ ;
	    }
	}
    }

    for( int i=0; i<R; i++ )
	printf("%s\n", S[i] ) ;

}

int main() {
    int A, B ;
    int cnt = 1 ;

    while( scanf("%d%d", &A, &B ) && (A || B) ) {
	if( cnt>1 )
	    printf("\n" ) ;
	printf("Field #%d:\n", cnt++ ) ;
	caso(A, B) ;
    }

    return 0 ;
}
