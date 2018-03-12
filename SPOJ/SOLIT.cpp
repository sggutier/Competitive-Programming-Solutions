#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
using namespace std ;
#define par pair<int,int>
#define r first
#define c second
#define x first
#define y second
const int lim = 8 ;
const int tamK = 200005 ;

struct cola {
	int ini, fin ;
	par arr[tamK][4] ;
	cola() {
		ini = 0 ;
		fin = 0 ;
	}
	void push( par _arr[4] ) {
		for( int i=0; i<4; i++ ) 
			arr[fin][i] = _arr[i] ;
		fin = (fin+1)%tamK ;
	}
	void front( par _arr[4] ) {
		for( int i=0; i<4; i++ )
			_arr[i] = arr[ini][i] ;
	}
	void pop() {
		ini = (ini+1)%tamK ;
	}
	bool empty() {
		return ini==fin ;
	}
};

int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
char usdA[lim][lim][lim][lim][lim][lim][lim][lim] ;
char usdB[lim][lim][lim][lim][lim][lim][lim][lim] ;
int W=0, T=0 ;
par ult[tamK][4] ;
cola Q ;

void dfs( par ini[4], char usd[lim][lim][lim][lim][lim][lim][lim][lim] ) {
	int minP ;
	par pos[4] ;

	usd[ini[0].x][ini[0].y][ini[1].x][ini[1].y][ini[2].x][ini[2].y][ini[3].x][ini[3].y] = 1 ;
	Q.push( ini ) ;
	while( !Q.empty() ) {
		Q.front( pos ) ;
		Q.pop() ;

		for( int k=0; k<4; k++ )
			ult[W][k] = pos[k] ;
		W ++ ;

		//for( int k=0; k<4; k++ ) 
			//printf("%d %d\n", pos[k].x+1, pos[k].y+1 ) ;
		//printf("--------------\n" ) ;
		//getchar() ;

		minP = usd[pos[0].x][pos[0].y][pos[1].x][pos[1].y][pos[2].x][pos[2].y][pos[3].x][pos[3].y] +1 ;
		if( minP == 6 ) 
			continue ;

		for( int k=0; k<4; k++ ) {
			par X, Y, Z ;
			X = pos[k] ;
			for( int d=0; d<4; d++ ) {
				Y = Z = X ;
				Y.r += dr[d] ;
				Y.c += dc[d] ;
				Z.r += 2*dr[d] ;
				Z.c += 2*dc[d] ;
				if( Y.r<0 || Y.r>=lim || Y.c<0 || Y.c>=lim )
					continue ;
				int w ;
				for( w=0; w<4; w++ ) {
					if( pos[w]==Y )
						break ;
				}
				if( w==4 ) {
					pos[k] = Y ;
					if( usd[pos[0].x][pos[0].y][pos[1].x][pos[1].y][pos[2].x][pos[2].y][pos[3].x][pos[3].y] ) {
						pos[k] = X ;
						continue ;
					}
					usd[pos[0].x][pos[0].y][pos[1].x][pos[1].y][pos[2].x][pos[2].y][pos[3].x][pos[3].y] = minP ;
					//for( int j=0; j<4; j++ )
						//printf("        %d %d\n", pos[j].x+1, pos[j].y+1 ) ;
					//printf("<<<<<<<<\n") ;
					Q.push( pos ) ;
					pos[k] = X ;
				}
				else if( Z.r>=0 && Z.r<lim && Z.c>=0 && Z.c<lim ) {
					for( w=0; w<4; w++ )
						if( pos[w]==Z )
							break ;
					if( w!=4 )
						continue ;
					pos[k] = Z ;
					if( usd[pos[0].x][pos[0].y][pos[1].x][pos[1].y][pos[2].x][pos[2].y][pos[3].x][pos[3].y] ) {
						pos[k] = X ;
						continue ;
					}
					usd[pos[0].x][pos[0].y][pos[1].x][pos[1].y][pos[2].x][pos[2].y][pos[3].x][pos[3].y] = minP ;
					//for( int j=0; j<4; j++ )
						//printf("        %d %d\n", pos[j].x+1, pos[j].y+1 ) ;
					//printf(">>>>>>>\n") ;
					Q.push( pos ) ;
					pos[k] = X ;
				}
			}
		}
	}
}

void caso() {
	par A[4], B[4] ;
	int res = 0 ;

	W = 0 ;
	T = 0 ;
	memset( usdA, 0, sizeof(usdA) ) ;
	memset( usdB, 0, sizeof(usdB) ) ;

	for( int i=0; i<4; i++ ) {
		scanf("%d%d", &A[i].x, &A[i].y ) ;
		A[i].x -- ;
		A[i].y -- ;
	}
	for( int i=0; i<4; i++ ) {
		scanf("%d%d", &B[i].x, &B[i].y ) ;
		B[i].x -- ;
		B[i].y -- ;
	}


	do {
		dfs( A, usdA ) ;
	} while( next_permutation(A,A+4) ) ;
	T = W ;
	do {
		dfs( B, usdB ) ;
	} while( next_permutation(B,B+4) ) ;

	for( int i=0; i<T; i++ ) {
		if( usdB[ ult[i][0].r ][ ult[i][0].c][ ult[i][1].r ][ ult[i][1].c][ ult[i][2].r ][ ult[i][2].c ][ ult[i][3].r ][ ult[i][3].c ] ) {
			res = 1 ;
			break ;
		}
	}

	printf("%s\n", res? "YES" : "NO" ) ;
}

int main() {
	int N ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		caso() ;

	return 0 ;
}

