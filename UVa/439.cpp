#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>
using namespace std ;
#define par pair<int,int>
#define r first
#define c second
const int lim = 8 ;

int minP[lim][lim][lim][lim] ;
int dr[] = { -2, -2, -1, -1, 1, 1, 2, 2 } ;
int dc[] = { -1, 1, -2, 2, -2, 2, -1, 1 } ;

void amp( int x, int y, int mat[lim][lim] ) {
    mat[x][y] = 0 ;
    queue <par> Q ;
    par pos, pos2 ;
    Q.push( par(x,y) ) ;

    while( !Q.empty() ) {
	pos = Q.front() ;
	Q.pop() ;
	for( int d=0; d<8; d++ ) {
	    pos2 = pos ;
	    pos2.r += dr[d] ;
	    pos2.c += dc[d] ;
	    if( pos2.r<0 || pos2.r>=lim || pos2.c<0 || pos2.c>=lim || mat[pos2.r][pos2.c]!=-1 )
		continue ;
	    mat[pos2.r][pos2.c] = mat[pos.r][pos.c]+1 ;
	    Q.push(pos2) ;
	}
    }
}

int main() {
    memset( minP, -1, sizeof(minP) ) ;

    char tmp[5],tmp2[5] ;

    for( int i=0; i<lim; i++ ) 
	for( int j=0; j<lim; j++ )
	    amp( i, j, minP[i][j] ) ;
    
    while( scanf("%s%s", tmp, tmp2)!=EOF ) {
	printf("To get from %s to %s takes %d knight moves.\n", tmp, tmp2, minP[tmp[0]-'a'][tmp[1]-'1'][tmp2[0]-'a'][tmp2[1]-'1'] ) ;
    }
    
    return 0 ;
}
