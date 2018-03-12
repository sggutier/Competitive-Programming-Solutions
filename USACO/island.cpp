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
const int limN = 50 ;
const int limB = 15 ;
const int limB2 = 1<<limB ;
#define r first
#define c second
typedef pair<int,int> par ;

int R, C, W=0 ;
char mapa[limN+5][limN+5] ;
int col[limN][limN] ;
int minP[limB][limB2] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
int disA[limN][limN] ;
int D[limB][limB] ;

struct dat {
	int p, msk, d ;
	dat() {
	}
	dat( int _p, int _msk, int _d ) {
		p = _p ;
		msk = _msk ;
		d = _d ;
	}
};

bool operator<( dat A, dat B ) {
	return A.d > B.d ;
}

void marcaCol() {
	for( int i=0; i<R; i++ )
		for( int j=0; j<C; j++ )
			col[i][j] = -1 ;
	for( int i=0; i<R; i++ ) {
		for( int j=0; j<C; j++ ) {
			if( mapa[i][j]!='X' || col[i][j]!=-1 )
				continue ;
			queue <par> qola ;
			qola.push( par(i,j) ) ;
			col[i][j] = W ;
			while( !qola.empty() ) {
				par pos = qola.front() ;
				qola.pop() ;
				for( int d=0; d<4; d++ ) {
					par pos2 = pos ;
					pos2.r += dr[d] ;
					pos2.c += dc[d] ;
					if( pos2.r<0 || pos2.r>=R || pos2.c<0 || pos2.c>=C )
						continue ;
					if( mapa[pos2.r][pos2.c]!='X' || col[pos2.r][pos2.c]!=-1 )
						continue ;
					col[pos2.r][pos2.c] = W ;
					qola.push( pos2 ) ;
				}
			}
			W ++ ;
		}
	}

	for( int i=0; i<W; i++ )
		for( int j=0; j<W; j++ )
			D[i][j] = (1<<30) ;

	for( int i=0; i<R; i++ ) {
		for( int j=0; j<C; j++ ) {
			if( mapa[i][j]!='X' || D[ col[i][j] ][ col[i][j] ]!=(1<<30)	)
				continue ;
			int K = col[i][j] ;
			queue <par> Q[2] ;
			int act=0, sig=1 ;

			for( int x=0; x<R; x++ ) {
				for( int y=0; y<C; y++ ) {
					if( col[x][y]==K ) {
						disA[x][y] = 0 ;
						Q[act].push( par(x,y) ) ;
					}
					else
						disA[x][y] = -1 ;
				}
			}

			while( !Q[act].empty() ) {
				while( !Q[act].empty() ) {
					par pos = Q[act].front() ;
					Q[act].pop() ;
	
					if( col[pos.r][pos.c] != -1 ) {
						D[col[pos.r][pos.c]][K] = min( D[col[pos.r][pos.c]][K], disA[pos.r][pos.c] ) ;
						D[K][col[pos.r][pos.c]] = min( D[K][col[pos.r][pos.c]], disA[pos.r][pos.c] ) ;
					}

					for( int d=0; d<4; d++ ) {
						par pos2 = pos ;
						pos2.r += dr[d] ;
						pos2.c += dc[d] ;
						if( pos2.r<0 || pos2.r>=R || pos2.c<0 || pos2.c>=C )
							continue ;
						if( mapa[pos2.r][pos2.c]=='.' || disA[pos2.r][pos2.c]!=-1 )
							continue ;
						if( mapa[pos2.r][pos2.c]=='X' ) {
							Q[act].push( pos2 ) ;
							disA[pos2.r][pos2.c] = disA[pos.r][pos.c] ;
						}
						else {
							Q[sig].push( pos2 ) ;
							disA[pos2.r][pos2.c] = disA[pos.r][pos.c] +1 ;
						}
					}
				}
				swap( act, sig ) ;

			}

		}
	}

}

void dijkstra() {
	priority_queue < dat > Q ;

	for( int i=0; i<W; i++ )
		for( int b=0; b<(1<<W); b++ )
			minP[i][b] = (1<<30) ;
	for( int i=0; i<W; i++ ) {
		minP[i][1<<i] = 1 ;
		Q.push( dat(i,1<<i,1) ) ;
	}

	while( !Q.empty() ) {
		dat pos = Q.top() ;
		Q.pop() ;

		if( pos.d>minP[pos.p][pos.msk] )
			continue ;

		minP[ pos.p ][ pos.msk ] = pos.d ;
		for( int i=0; i<W; i++ ) {
			if( (1<<i) & pos.msk )
				continue ;
			dat pos2 = pos ;
			pos2.p = i ;
			pos2.msk |= (1<<i) ;
			pos2.d += D[pos.p][i] ;

			if( minP[pos2.p][pos2.msk]<=pos2.d )
				continue ;

			minP[pos2.p][pos2.msk] = pos2.d ;
			Q.push( pos2 ) ;
		}
	}
}

int main() {
	freopen( "island.in", "r", stdin ) ;
	freopen( "island.out", "w", stdout ) ;

	int foo = 0 ;
	int res = (1<<30) ;

	scanf("%d%d", &R, &C ) ;
	for( int i=0; i<R; i++ )
		scanf("%s", mapa[i] ) ;

	marcaCol() ;
	dijkstra() ;

	for( int i=0; i<W; i++ ) {
		res = min( res, minP[i][(1<<W)-1] ) ;
	}

	printf("%d\n", res-1 ) ;

	return 0 ;
}


