#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std ;
const int limN = 105 ;
const int limB = (1<<7) ;
const int B = 7 ;

struct sta {
	int r, c, k ;
	sta() {
	}
	sta( int _r, int _c, int _k ) {
		r = _r ;
		c = _c ;
		k = _k ;
	}
};

bool operator==( sta A, sta B ) {
	return A.r==B.r && A.c==B.c && A.k==B.k ;
}

int R, C ;
char arr[limN][limN] ;
int kas[limN][limN] ;
int minP[limN][limN][limB] ;
int maxC[limN][limN][limB] ;
queue <sta> Q ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

int main() {
	sta pos, fin ;
	int K = 0 ;

	scanf("%d%d", &R, &C ) ;
	for( int i=0; i<R; i++ ) {
		scanf("%s", arr[i] ) ;
		for( int j=0; j<C; j++ ) {
			if( arr[i][j]=='M' ) {
				pos = sta( i, j, 0 ) ;
				arr[i][j] = '.' ;
			}
			else if( arr[i][j]=='P' ) {
				fin = sta( i, j, limB-1 ) ;
				arr[i][j] = '.' ;
			}
			else if( arr[i][j]=='L' ) {
				kas[i][j] = K++ ;
			}
		}
	}
	fin.k = (1<<K)-1 ;

	minP[pos.r][pos.c][pos.k] = 1 ;
	Q.push(pos) ;
	while( !Q.empty() ) {
		pos = Q.front() ;
		Q.pop() ;
		if( pos==fin ) {
			printf("%d %d\n", minP[pos.r][pos.c][pos.k]-1, maxC[pos.r][pos.c][pos.k] ) ;
			return 0 ;
		}
		if( minP[pos.r][pos.c][pos.k]%2==1 && arr[pos.r][pos.c]=='m' ) {
			maxC[pos.r][pos.c][pos.k] ++ ;
		}
		//printf("%d %d %d -> %d %d -> %c %d\n", pos.r+1, pos.c+1, pos.k, maxC[pos.r][pos.c][pos.k], minP[pos.r][pos.c][pos.k],arr[pos.r][pos.c], minP[pos.r][pos.c][pos.k]%2==1 && arr[pos.r][pos.c]=='m' ) ;
		//getchar() ;
		for( int d=0; d<4; d++ ) {
			sta pos2 = pos ;
			pos2.r += dr[d] ;
			pos2.c += dc[d] ;
			if( arr[pos.r][pos.c]=='L' )
				pos2.k |= (1<<kas[pos.r][pos.c]) ;
			if( pos2.r < 0 || pos2.r >= R || pos2.c < 0 || pos2.c >= C || arr[pos2.r][pos2.c]=='#' )
				continue ;
			if( minP[pos2.r][pos2.c][pos2.k]==0 ) {
				minP[pos2.r][pos2.c][pos2.k] = minP[pos.r][pos.c][pos.k] +1 ;
				Q.push(pos2) ;
			}
			if( minP[pos2.r][pos2.c][pos2.k] <= minP[pos.r][pos.c][pos.k]+1 )
				maxC[pos2.r][pos2.c][pos2.k] = max( maxC[pos.r][pos.c][pos.k], maxC[pos2.r][pos2.c][pos2.k] ) ;
		}
	}

	printf("-1\n" ) ;

	return 0 ;
}
