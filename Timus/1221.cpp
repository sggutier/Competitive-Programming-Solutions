#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 4005 ;
const int lim2 = 2005 ;

int N ;
bool arr[lim2][lim2], arrDia[lim][lim] ;
int cargNorm[lim2][lim2], cargDia[lim][lim] ;
short giroX[lim2][lim2], giroY[lim2][lim2] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

char pal[2001];

int subArea2( int carg[lim2][lim2], int x1, int y1, int x2, int y2 ) {
	if( x1>x2 )
		swap( x1, x2 ) ;
	if( y1>y2 )
		swap( y1, y2 ) ;
	x1 --, y1 -- ;
	return carg[x2][y2] + carg[x1][y1] - carg[x1][y2] - carg[x2][y1] ;
}

int subArea( int carg[lim][lim], int x1, int y1, int x2, int y2 ) {
	if( x1>x2 )
		swap( x1, x2 ) ;
	if( y1>y2 )
		swap( y1, y2 ) ;
	x1 --, y1 -- ;
	return carg[x2][y2] + carg[x1][y1] - carg[x1][y2] - carg[x2][y1] ;
}

void precalcCarg2( bool org[lim2][lim2], int cpy[lim2][lim2] ) {
	for( int i=0; i<lim2; i++ ) {
		for( int j=0; j<lim2; j++ ) {
			cpy[i][j] = org[i][j] ;
			if( i )
				cpy[i][j] += cpy[i-1][j] ;
			if( j )
				cpy[i][j] += cpy[i][j-1] ;
			if( i && j )
				cpy[i][j] -= cpy[i-1][j-1] ;
		}
	}
}

void precalcCarg( bool org[lim][lim], int cpy[lim][lim] ) {
	for( int i=0; i<lim; i++ ) {
		for( int j=0; j<lim; j++ ) {
			cpy[i][j] = org[i][j] ;
			if( i )
				cpy[i][j] += cpy[i-1][j] ;
			if( j )
				cpy[i][j] += cpy[i][j-1] ;
			if( i && j )
				cpy[i][j] -= cpy[i-1][j-1] ;
		}
	}
}

void precalculaGiro() {
	int K = 1000 ;
	int w = 0 ;

	for( int i=0; i<=K; i++, w++ ) 
		for( int r=i, c=0; r>=0 && c<=K; r--, c++ ) 
			giroX[r][c] = w ;
	for( int j=1; j<=K; j++, w++ ) 
		for( int r=K, c=j; r>=0 && c<=K; r--, c++ ) 
			giroX[r][c] = w ;

	w = 0 ;
	for( int j=0; j<=K; j++, w++ ) 
		for( int r=K, c=j; r>=0 && c>=0; r--, c-- ) 
			giroY[r][c] = w ;
	for( int i=K-1; i>=0; i--, w++ ) 
		for( int r=i, c=K; r>=0 && c>=0; r--, c-- ) 
			giroY[r][c] = w ;
}

int negOfCuad( int k ) {
	return k*(k+1)*2 ;
}

void caso() {
	int res = 0 ;

	memset( arr, 0, sizeof(arr) ) ;
	memset( arrDia, 0, sizeof(arrDia) ) ;
	memset( cargNorm, 0, sizeof(cargNorm) ) ;
	memset( cargDia, 0, sizeof(cargDia) ) ;

	for( int i=1; i<=N; i++ ) {
	     scanf("%s",pal);
		for( int j=1; j<=N; j++ ) {
		    if(pal[j-1]=='.')
			arr[i][j]=1;
			else
			arr[i][j]=0;
			arrDia[ giroX[i][j] ][ giroY[i][j] ] = arr[i][j] ;
		}
	}

	precalcCarg2( arr, cargNorm ) ;
	precalcCarg( arrDia, cargDia ) ;

	for( int i=1; i<=N; i++ ) {
		for( int j=1; j<=N; j++ ) {
			if( arr[i][j] ) 
				continue ;
			int maxK = min( min(N-i,i-1), min(N-j,j-1)  )  ;
			int quak = 0 ;
			for( int k=1; k<=maxK; k++ )  {
				bool posb = 1 ;
				for( int d=0, x, y, x2, y2; d<4; d++ ) {
					x = i + k*dr[d] ;
					y = j + k*dc[d] ;
					x2 = i + k*dr[(d+1)%4] ;
					y2 = j + k*dc[(d+1)%4] ;
					if( subArea( cargDia, giroX[x][y],giroY[x][y],giroX[x2][y2],giroY[x2][y2] ) )
						posb = 0 ;
				}
				if( !posb )
					break ;
				if( subArea2( cargNorm, i-k, j-k, i+k, j+k )==negOfCuad(k)  ) {
					res = max( res, k ) ;
					quak = k ;
				}
			}
		}
	}

	if( res ) 
		printf("%d\n", 2*res+1 ) ;
	else
		printf("-1\n" ) ;
}

int main() {
	precalculaGiro() ;

	scanf("%d", &N ) ;
	//while( N ) {
		caso() ;
	//}

	return 0 ;
}
