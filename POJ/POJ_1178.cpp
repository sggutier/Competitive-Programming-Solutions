#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;
const int limN = 8 ;
const int limK = 64 ;
const int limQ = 100005 ;
typedef pair<int,int> par ;
#define r first
#define c second

template <class tip> class cola {
	int ini, fin ;
	tip arr[limQ] ;
	public:
	cola() {
		ini = 0 ;
		fin = 0 ;
	}
	void push( tip W ) {
		arr[fin++] = W ;
		fin %= limQ ;
	}
	void pop() {
		ini = (ini+1)%limQ ;
	}
	bool empty() {
		return ini==fin ;
	}
	tip front() {
		return arr[ini] ;
	}
};

cola <par> Q ;

struct mapa {
	char minP[limN][limN][limN][limN] ;
	int D ;
	int dr[8], dc[8] ;
	mapa() {
	}
	void amp( par ini ) {
		par pos ;
		minP[ini.r][ini.c][ini.r][ini.c] = 1 ;
		Q.push(ini) ;

		while( !Q.empty() ) {
			pos = Q.front() ;
			Q.pop() ;
			for( int d=0; d<D; d++ ) {
				par pos2 = pos ;
				pos2.r += dr[d] ;
				pos2.c += dc[d] ;
				if( pos2.r<0 || pos2.r>=limN || pos2.c<0 || pos2.c>=limN || minP[ini.r][ini.c][pos2.r][pos2.c] )
					continue ;
				minP[ini.r][ini.c][pos2.r][pos2.c] = minP[ini.r][ini.c][pos.r][pos.c]+1 ;
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

mapa rey, cab ;

int main() {
	int N = 0, W=0 ; 
	par K, C[limK] ;
	char tmp[limK*3] ;
	int res = (1<<30) ;

	scanf("%s", tmp ) ;
	W = strlen(tmp) ;
	
	rey.D = 8 ;
	rey.dr[0] = -1, rey.dc[0] = -1 ;
	rey.dr[1] = -1, rey.dc[1] =  0 ;
	rey.dr[2] = -1, rey.dc[2] =  1 ;
	rey.dr[3] =  0, rey.dc[3] = -1 ;
	rey.dr[4] =  0, rey.dc[4] =  1 ;
	rey.dr[5] =  1, rey.dc[5] = -1 ;
	rey.dr[6] =  1, rey.dc[6] =  0 ;
	rey.dr[7] =  1, rey.dc[7] =  1 ;
	rey.amplitudes() ;

	cab.D = 8 ;
	cab.dr[0] = -2, cab.dc[0] = -1 ;
	cab.dr[1] = -2, cab.dc[1] = 1 ;
	cab.dr[2] = -1, cab.dc[2] = -2 ;
	cab.dr[3] = -1, cab.dc[3] = 2 ;
	cab.dr[4] = 1, cab.dc[4] = -2 ;
	cab.dr[5] = 1, cab.dc[5] = 2 ;
	cab.dr[6] = 2, cab.dc[6] = -1 ;
	cab.dr[7] = 2, cab.dc[7] = 1 ;
	cab.amplitudes() ;

	K = par( tmp[0]-'A', tmp[1]-'1' ) ;
	for( int i=2; i<W; i+=2 ) {
		C[N++] = par( tmp[i]-'A', tmp[i+1]-'1' ) ;
	}

	for( int i=0; i<limN; i++ ) {
		for( int j=0; j<limN; j++ ) {
			int tmp = 0 ;
			tmp += rey.minP[ K.r ][ K.c ][i][j] ;
			for( int a=0; a<N; a++ ) {
				tmp += cab.minP[ C[a].r ][ C[a].c ][i][j] ;
			}
			res = min( res, tmp ) ;
			for( int x=0; x<N; x++ ) {
				for( int a=0; a<limN; a++ ) {
					for( int b=0; b<limN; b++ ) {
						tmp = 0 ;
						tmp += rey.minP[ K.r ][ K.c ][a][b] ;
						tmp += cab.minP[ C[x].r ][ C[x].c ][a][b] ;
						tmp += cab.minP[ a ][ b ][i][j] ;
						for( int w=0; w<N; w++ ) {
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

