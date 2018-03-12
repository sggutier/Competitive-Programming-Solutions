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
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define r first
#define c second
const int lim = 805 ;
const int lim2 = lim*lim ;

struct cola {
	int ini, fin ;
	par arr[lim2] ;
	cola() {
		ini = 0 ;
		fin = 0 ;
	}
	void push( par tmp ) {
		arr[fin] = tmp ;
		fin = (fin+1)%lim2 ;
	}
	void pop() {
		ini = (ini+1)%lim2 ;
	}
	bool empty() {
		return ini==fin ;
	}
	par front() {
		return arr[ini] ;
	}
	void reset() {
		ini = 0 ;
		fin = 0 ;
	}
};

int N, W ;
char mapa[lim][lim] ;
int bP[lim][lim] ;
int minP[lim][lim] ;
cola Q ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

void ampAbj() {
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if( mapa[i][j]=='H' ) {
				Q.push( par(i,j) ) ;
				bP[i][j] = 1 ;
				mapa[i][j] = 'G' ;
			}
		}
	}

	while( !Q.empty() ) {
		par pos = Q.front() ;
		Q.pop() ;

		for( int d=0; d<4; d++ ) {
			par pos2 = pos ;
			pos2.r += dr[d] ;
			pos2.c += dc[d] ;
			if( pos2.r<0 || pos2.r>=N || pos2.c<0 || pos2.c>=N || mapa[pos2.r][pos2.c]!='G' || bP[pos2.r][pos2.c] )
				continue ;
			bP[pos2.r][pos2.c] = bP[pos.r][pos.c] +1 ;
			Q.push(pos2) ;
		}
	}
}

bool sePuede( int sta, par pos ) {
	memset( minP, 0, sizeof(minP) ) ;

	if( sta>=bP[pos.r][pos.c] )
		return 0 ;

	minP[pos.r][pos.c] = sta ;
	Q.push(pos) ;
	while( !Q.empty() ) {
		par pos = Q.front() ;
		Q.pop() ;

		if( mapa[pos.r][pos.c]=='D' )  {
			Q.reset() ;
			return 1 ;
		}

		for( int d=0; d<4; d++ ) {
			par pos2 = pos ;
			pos2.r += dr[d] ;
			pos2.c += dc[d] ;
			if( pos2.r<0 || pos2.r>=N || pos2.c<0 || pos2.c>=N || mapa[pos2.r][pos2.c]=='T' || minP[pos2.r][pos2.c] ) 
				continue ;
			if( bP[pos2.r][pos2.c] && (minP[pos.r][pos.c]-sta+1)/W + sta >= bP[pos2.r][pos2.c] )
				continue ;
			minP[pos2.r][pos2.c] = minP[pos.r][pos.c] +1 ;
			Q.push(pos2) ;
		}
	}

	return 0 ;
}

void caso() {
	int ini=0, fin=lim2 ;
	par posIni ;

	memset( bP, 0, sizeof(bP) ) ;

	scanf("%d%d", &N, &W ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", mapa[i] ) ;
		for( int j=0; j<N; j++ ) {
			if( mapa[i][j]=='M' ) {
				posIni = par( i, j ) ;
				mapa[i][j] = 'G' ;
			}
		}
	}
	
	ampAbj() ;

	while( ini<fin ) {
		int piv = (ini+fin)/2 +1 ;
		if( sePuede(piv,posIni) )
			ini = piv ;
		else
			fin = piv-1 ;
	}

	printf("%d\n", ini-1 ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) 
		caso() ;
	
	return 0 ;
}



