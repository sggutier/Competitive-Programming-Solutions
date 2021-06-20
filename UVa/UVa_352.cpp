#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 105 ;

int N ;
char S[lim][lim] ;
int dr[] = { -1, 0, 1, 0, -1, -1, 1, 1 } ;
int dc[] = { 0, 1, 0, -1, -1, 1, -1, 1 } ;

int ff( int r, int c ) {
    if( r<0 || r>=N || c<0 || c>=N || S[r][c]=='0' )
	return 0 ;
    int res = 1 ;
    S[r][c] = '0' ;
    for( int d=0; d<8; d++ )
	res += ff( r+dr[d], c+dc[d] ) ;
    return res ;
}

void caso() {
    int res = 0 ;
    
    for( int i=0; i<N; i++ )
	scanf("%s", S[i] ) ;

    for( int i=0; i<N; i++ )
	for( int j=0; j<N; j++ )
	    if( ff(i,j) )
		res ++ ;

    printf("%d war eagles.\n", res ) ;
}

int main() {
    int T = 0 ;

    while( scanf("%d",&N)!=EOF ) {
	printf("Image number %d contains ", ++T ) ;
	caso() ;
    }
    
    return 0 ;
}
