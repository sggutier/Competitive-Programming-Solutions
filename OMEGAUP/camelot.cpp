#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std ;
const int limN = 8 ;
const int limK = 64 ;
typedef pair<int,int> par ;
#define r first
#define c second

struct mapa {
	int minP[limN][limN][limN][limN] ;
	int D ;
	int dr[8], dc[8] ;
	mapa() {
	}
	void amp( par ini ) {
		par pos ;
		minP[ini.r][ini.c][ini.r][ini.c] = 1 ;
		queue <par> Q ;
		Q.push(ini) ;

		while( !Q.empty() ) {
			pos = Q.front() ;
			Q.pop() ;
			for( int d=0; d<D; d++ ) {
				par pos2 = pos ;
				pos.r += dr[d] ;
				pos.c += dc[d] ;
				if( pos2.r<0 || pos2.r>=limN || pos2.c<0 || pos2.c>=limN || minP[ini.r][ini.c][pos2.r][pos2.c] )
					continue ;
				minP[ini.r][ini.c][pos2.r][pos2.c] = minP[ini.r][ini.c][pos2.r][pos2.c]+1 ;
				Q.push(pos2) ;
			}
		}
	}
	void amplitudes() {
		for( int i=0; i<limN; i++ ) {
			for( int j=0; j<limN; j++ ) {
				amp( par(i,j) ) ;
				for( int a=0; a<limN; a++ ) 
					for( int b=0; b<limN; b++ )
						minP[i][j][a][b] -- ;
			}
		}
	}
};

int main() {
	mapa rey, cab ;
	int N = 0, W=0 ; 
	par K, C[limK] ;
	char tmp[100] ;
	int res = (1<<30) ;

	rey.D = 4 ;
	rey.dr[0] = -1, rey.dc[0] = 0 ;
	rey.dr[0] = 0, rey.dc[0] = 1 ;
	rey.dr[0] = 1, rey.dc[0] = 0 ;
	rey.dr[0] = 0, rey.dc[0] = -1 ;

	cab.D = 8 ;
	cab.dr[0] = -2, cab.dc[0] = -1 ;
	cab.dr[0] = -2, cab.dc[0] = 1 ;
	cab.dr[0] = -1, cab.dc[0] = -2 ;
	cab.dr[0] = -1, cab.dc[0] = 2 ;
	cab.dr[0] = 1, cab.dc[0] = -2 ;
	cab.dr[0] = 1, cab.dc[0] = 2 ;
	cab.dr[0] = 2, cab.dc[0] = -1 ;
	cab.dr[0] = 2, cab.dc[0] = 1 ;

	gets(tmp) ;
	W = strlen(tmp) ;

	K = par( tmp[0]-'A', tmp[1]-'0' ) ;
	for( int i=2; i<W; i+=2 ) {
		C[N++] = par( tmp[i]-'A', tmp[i+1]-'0' ) ;
	}

	for( int i=0; i<limN; i++ ) {
		for( int j=0; j<limN; j++ ) {
			int tmp = 0 ;
			tmp += rey.minP[ K.r ][ K.c ][i][j] ;
			for( int a=0; a<K; a++ ) {
				tmp += cab.minP[ C[a].r ][ C[a].c ][i][j] ;
			}
			res = min( res, tmp ) ;
			for( int x=0; x<K; x++ ) {
				for( int a=0; a<limN; a++ ) {
					for( int b=0; b<limN; b++ ) {
						tmp = 0 ;
						tmp += rey.minP[ K.r ][ K.c ][a][b] ;
						tmp += cab.minP[ C[x].r ][ C[x].c ][a][b] ;
						tmp += cab.minP[ a ][ b ][i][j] ;
						for( int w=0; w<K; w++ ) {
							if( w!=x )
								tmp += cab.minP[ C[w].r ][ C[w].c ][i][j] ;
						}
						res = min( res, tmp ) ;
					}
				}
			}
		}
	}

	printf("%d\n", res ) ;

	return 0 ;
}

