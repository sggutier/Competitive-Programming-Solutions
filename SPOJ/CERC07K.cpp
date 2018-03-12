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
const int lim = 105 ;
const int limB = 1<<4 ;

struct cor {
	int r, c, msk ;
	cor() {
	}
	cor( int _r, int _c, int _msk ) {
		r = _r ;
		c = _c ;
		msk = _msk ;
	}
};

int R, C ;
char mapa[lim][lim] ;
queue <cor> Q ;
int minP[lim][lim][limB] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
char val[300] ;

void caso() {
	int res = (1<<30) ;

	memset( minP, 0, sizeof(minP) ) ;

	for( int i=0; i<R; i++ )
		scanf("%s", mapa[i] ) ;

	for( int i=0; i<R; i++ )  {
		for( int j=0; j<C; j++ ) {
			if( mapa[i][j]=='*' ) {
				Q.push( cor(i,j,0) ) ;
				minP[i][j][0] = 1 ;
			}
			else if( mapa[i][j]=='X' )
				mapa[i][j] = '0' ;
		}
	}

	while( !Q.empty() ) {
		cor pos = Q.front() ;
		int w = minP[pos.r][pos.c][pos.msk] +1 ;
		Q.pop() ;

		if( mapa[pos.r][pos.c]>='a' && mapa[pos.r][pos.c]<='z' && !((1<<val[ mapa[pos.r][pos.c] ]) & pos.msk)  ) {
			pos.msk |= (1<<val[ mapa[pos.r][pos.c]]) ;
			minP[pos.r][pos.c][pos.msk] = w-1 ;
			Q.push(pos) ;
			continue ;
		}
		if( mapa[pos.r][pos.c]=='0' ) 
			res = min( res, w-1 ) ;

		for( int d=0; d<4; d++ ) {
			cor pos2 = pos ;
			pos2.r += dr[d] ;
			pos2.c += dc[d] ;
			if( pos2.r<0 || pos2.r>=R || pos2.c<0 || pos2.c>=C || mapa[pos2.r][pos2.c]=='#' || minP[pos2.r][pos2.c][pos2.msk] )
				continue ;
			if( mapa[pos2.r][pos2.c]>='A' && mapa[pos2.r][pos2.c]<='Z' && !((1<<val[ mapa[pos2.r][pos2.c] ]) & pos2.msk )   )
				continue ;
			minP[pos2.r][pos2.c][pos2.msk] = w ;
			Q.push(pos2) ;
		}
	}

	if( res==(1<<30)  )
		printf("The poor student is trapped!\n" ) ;
	else
		printf("Escape possible in %d steps.\n", res-1 ) ;
}

int main() {
	val['R'] = 0 ;
	val['G'] = 1 ;
	val['B'] = 2 ;
	val['Y'] = 3 ;
	val['r'] = 0 ;
	val['g'] = 1 ;
	val['b'] = 2 ;
	val['y'] = 3 ;
	
	scanf("%d%d", &R, &C) ;
	while( R!=0 && C!=0 ) {
		caso() ;
		scanf("%d%d", &R, &C)  ;
	}

	return 0 ;
}

