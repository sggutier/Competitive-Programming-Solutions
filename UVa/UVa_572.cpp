#include <cstdio>
#include <algorithm>
#include <utility>
#include <stack>
#include <iostream>
using namespace std ;
const int lim = 105 ;

int N, M ;
char grd[lim][lim] ;
int dr[] = { -1, 0, 1, 0, -1, -1, 1, 1 } ;
int dc[] = { 0, -1, 0, 1, -1, 1, -1, 1 } ;

void ff( int r, int c ) {
    if( r<0 || r>=N || c<0 || c>=M || grd[r][c]=='*' )
	return ;
    grd[r][c] = '*' ;
    for( int d=0; d<8; d++ )
	ff( r+dr[d], c+dc[d] ) ;
}

void caso() {
    int res = 0 ;
    for( int i=0; i<N; i++ )
	scanf("%s", grd[i] ) ;
    for( int i=0; i<N; i++ ) {
	for( int j=0; j<M; j++ ) {
	    if( grd[i][j]=='*' )
		continue ;
	    ff( i, j ) ;
	    res ++ ;
	}
    }
    printf("%d\n", res ) ;
}

int main() {
    while( scanf("%d%d", &N, &M) != EOF && (N||M) )
	caso() ;
    return 0 ;
}
