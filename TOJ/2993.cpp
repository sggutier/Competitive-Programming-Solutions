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
#include <list>
#include <stack>
using namespace std ;
const int lim = 50 ;
const int inf = (1<<30) ;
typedef pair<int,int> par ;
#define r first
#define c second

int N, W ;
char mapa[lim+5][lim+5] ;
queue <par> Q, Q2 ;
int dis[lim][lim][lim][lim] ;
int minP[lim][lim][lim][lim] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

void reset() {
	while( !Q.empty() ) 
		Q.pop() ;
	while( !Q2.empty() ) 
		Q2.pop() ;
	for( int i=0; i<lim; i++ ) {
		for( int j=0; j<lim; j++ )  {
			for( int k=0; k<lim; k++ )  {
				for( int a=0; a<lim; a++ )  {
					dis[i][j][k][a] = inf ;
					minP[i][j][k][a] = inf ;
				}
			}
		}
	}
}

void amp( par ini ) {
	int d ;
	par pos, sig ;

	dis[ini.r][ini.c][ini.r][ini.c] = 0 ;
	Q.push( ini ) ;
	while( !Q.empty() ) {
		pos = Q.front() ;
		Q.pop() ;

		int tmp = dis[ ini.r ][ ini.c ][pos.r][ pos.c ] +1 ;

		for( int d=0; d<4; d++ ) {
			sig = pos ;
			sig.r += dr[d] ;
			sig.c += dc[d] ;

			if( sig.r<0 || sig.r>=N || sig.c<0 || sig.c>=N || mapa[sig.r][sig.c]=='#' )
				continue ; 

			if( dis[ini.r][ini.c][ sig.r ][ sig.c ] != inf )
				continue ;

			dis[ini.r][ini.c][ sig.r ][ sig.c ] = tmp ;
			Q.push( sig ) ;
		}
	}
}

void caso() {
	reset() ;

	par posA, posB, sigA, sigB ;
	par finA, finB ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", mapa[i] ) ;
		for( int j=0; j<N; j++ ) {
			if( mapa[i][j] == 'Z' ) {
				posA = par( i, j ) ;
				mapa[i][j] = '.' ;
			}
			else if( mapa[i][j]=='W' ) {
				posB = par( i, j ) ;
				mapa[i][j] = '.' ;
			}
			else if( mapa[i][j]=='C' ) {
				finA = par( i, j ) ;
				mapa[i][j] = '.' ;
			}
			else if( mapa[i][j]=='M' ) {
				finB = par( i, j ) ;
				mapa[i][j] = '.' ;
			}
		}
	}
	scanf("%d", &W ) ;

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if( mapa[i][j]=='.' ) {
				amp( par(i,j) ) ;
			}
		}
	}

	minP[ posA.r ][ posA.c ][ posB.r ][ posB.c ] = 0 ;
	Q.push( posA ) ;
	Q2.push( posB ) ;
	while( !Q.empty() ) {
		posA = Q.front() ;
		posB = Q2.front() ;
		Q.pop() ;
		Q2.pop() ;

		int tmp = minP[ posA.r ][ posA.c ][ posB.r ][ posB.c ] +1 ;

		for( int d=0; d<4; d++ ) {
			sigA = posA ;
			sigB = posB ;
			sigA.r += dr[d] ;
			sigA.c += dc[d] ;

			if( sigA.r<0 || sigA.r>=N || sigA.c<0 || sigA.c>=N || mapa[sigA.r][sigA.c]=='#' )
				continue ; 

			if( dis[ sigA.r ][ sigA.c ][ sigB.r ][ sigB.c ] <= W )
				continue ;

			if( minP[sigA.r][sigA.c][sigB.r][sigB.c] != inf )
				continue ;

			minP[sigA.r][sigA.c][sigB.r][sigB.c] = tmp ;
			Q.push( sigA ) ;
			Q2.push( sigB ) ;
		}
		for( int d=0; d<4; d++ ) {
			sigA = posA ;
			sigB = posB ;
			sigB.r += dr[d] ;
			sigB.c += dc[d] ;

			if( sigB.r<0 || sigB.r>=N || sigB.c<0 || sigB.c>=N || mapa[sigB.r][sigB.c]=='#' )
				continue ; 

			if( dis[ sigA.r ][ sigA.c ][ sigB.r ][ sigB.c ] <= W )
				continue ;

			if( minP[sigA.r][sigA.c][sigB.r][sigB.c] != inf )
				continue ;

			minP[sigA.r][sigA.c][sigB.r][sigB.c] = tmp ;
			Q.push( sigA ) ;
			Q2.push( sigB ) ;
		}
	}

	printf("%s\n", (minP[finA.r][finA.c][finB.r][finB.c] != inf)? "Yes" : "No" ) ;

}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ )
		caso() ;

	return 0 ;
}


