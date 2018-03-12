#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std ;
#define limN 305
#define limP 52

struct coor {
	int r, c, p ;
	coor() {
	}
	coor( int a, int b, int d ) {
		r = a ;
		c = b ;
		p = d ;
	}
};

int minP[limN][limN][limP] ;
queue <coor> Q ;

int main() {
	int N, P ;
	int mapa[limN][limN] ;
	int pat[limP] ;
	int dr[] = { -1, 0, 1, 0 } ;
	int dc[] = { 0, 1, 0, -1 } ;
	int res = (1<<30) ;
	
	scanf("%d%d", &N, &P ) ;
	for( int i=0; i<P; i++ )
		scanf("%d", &pat[i] ) ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			scanf("%d", &mapa[i][j] ) ;
			for( int k=0; k<P; k++ )
				minP[i][j][k] = -1 ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		if( mapa[0][i] == 1 )
			Q.push(  coor(0,i,-1)   )  ;
	}
	
	while( !Q.empty()   )   {
		coor pos = Q.front(), pos2  ;
		pos.p ++ ;
		Q.pop() ;
		for( int d=0; d<4; d++ ) {
			pos2 = pos ;
			pos2.r += dr[d] ;
			pos2.c += dc[d] ;
			if( pos2.r <0 || pos2.r>=N  ||  pos2.c<0 || pos2.c>=N  )  
				continue ;
			if( minP[pos2.r][pos2.c][pos2.p%P] != -1    )
				continue ;
			if(   pat[pos2.p%P] != mapa[pos2.r][pos2.c]     &&   !(pos2.r==N-1  && mapa[pos2.r][pos2.c]==1)        )  
				continue ;
				
			minP[pos2.r][pos2.c][pos2.p%P] = pos.p ;
			Q.push( pos2 ) ;
		}
	}
	
	for( int j=0; j<N; j++ ) {
		if( mapa[N-1][j] != 1 )
			continue ;
		for( int k=0; k<P; k++ ) {
			if( minP[N-1][j][k]  != -1  )
				res = min( res,  minP[N-1][j][k]   )  ;
		}
	}
	printf("%d\n", res+2 ) ;
	
	return 0 ;
}

