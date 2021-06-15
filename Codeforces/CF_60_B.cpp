#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <stack>
using namespace std ;
const int lim = 11 ;
const int D = 6 ;

int A, B, C ;
char mapa[lim][lim][lim] ;
int minP[lim][lim][lim] ;
int dx[] = { -1, 1, 0, 0, 0, 0 } ;
int dy[] = { 0, 0, 1, -1, 0, 0 } ;
int dz[] = { 0, 0, 0, 0, 1, -1 } ;
queue <int> qX, qY, qZ ;

int main() {
	int x, y, z ;
	int r, c, k ;
	int res = 0 ;

	scanf("%d%d%d", &A, &B, &C ) ;
	for( int i=0; i<A; i++ ) {
		for( int j=0; j<B; j++ )
			scanf("%s", mapa[i][j] ) ;
	}
	scanf("%d%d", &y, &z ) ;
	x = 0 ;
	y--, z-- ;

	minP[x][y][z] = 1 ;
	qX.push(x) ;
	qY.push(y) ;
	qZ.push(z) ;
	while( !qX.empty() ) {
		x = qX.front() ;
		y = qY.front() ;
		z = qZ.front() ;
		qX.pop() ;
		qY.pop() ;
		qZ.pop() ;

		res ++ ;

		for( int d=0; d<D; d++ ) {
			r = x+dx[d] ;
			c = y+dy[d] ;
			k = z+dz[d] ;
			if( r<0 || r>=A || c<0 || c>=B || k<0 || k>=C || mapa[r][c][k]=='#' || minP[r][c][k] )
				continue ;
			minP[r][c][k] = minP[x][y][z]+1 ;
			qX.push(r) ;
			qY.push(c) ;
			qZ.push(k) ;
		}
	}

	printf("%d\n", res ) ;

	return 0 ;
}

