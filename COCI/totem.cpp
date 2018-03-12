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
const int lim = 1005 ;
#define r first
#define c second
typedef pair<int,int> par ;

int N ;
int arr[lim][lim] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
queue <par> Q ;
int minP[lim][lim], ant[lim*lim] ;
int id[lim][lim] ;
par red[lim*lim] ;

int main() {
	int M ;
	int W = 0 ;

	scanf("%d", &N ) ;
	M = N*2 ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N-i%2; j++ ) {
			int a, b ;
			scanf("%d%d", &a, &b ) ;
			arr[i][ 2*j + i%2 ] = a ;
			arr[i][ 2*j + i%2 +1 ] = b ;
			id[i][ 2*j + i%2 ] = W ;
			id[i][ 2*j + i%2 +1 ] = W ;
			red[W] = par( i, 2*j + i%2 ) ;
			W ++ ;
		}
	}

	while( minP[0][0]==0 ) {
		par foo = red[W-1], foo2 = foo ;
		foo2.c ++ ;
		minP[ foo.r ][ foo.c ] = 1 ;
		minP[ foo2.r ][ foo2.c ] = 1 ;
		ant[W-1] = -1 ;
		Q.push( foo ) ;
		Q.push( foo2 ) ;
		W -- ;
		while( !Q.empty() ) {
			par pos = Q.front() ;
			Q.pop() ;
	
			//printf("%d -> %d -> %d %d\n", id[pos.r][pos.c], ant[ id[pos.r][pos.c] ], pos.r, pos.c ) ;
	
			for( int d=0; d<4; d++ )  {
				par pos2 = pos ;
				pos2.r += dr[d] ;
				pos2.c += dc[d] ;
				if( pos2.r<0 || pos2.r>=N || pos2.c<0 || pos2.c>=M || minP[pos2.r][pos2.c] || arr[pos2.r][pos2.c]!=arr[pos.r][pos.c] )
					continue ;
				par pos3 = pos2 ;
				pos3.c = ( ( pos2.c-pos2.r%2 ) / 2 ) *2  +  pos2.r%2 ;
				if( pos3.c == pos2.c )
					pos3.c ++ ;
				minP[pos2.r][pos2.c] = minP[pos.r][pos.c] +1 ;
				minP[pos3.r][pos3.c] = minP[pos.r][pos.c] +1 ;
				ant[ id[pos2.r][pos2.c] ] = id[pos.r][pos.c] ;
				Q.push( pos2 ) ;
				Q.push( pos3 ) ;
			}
		}
		//printf("---------\n" ) ;
		//getchar() ;
	}

	printf("%d\n", minP[0][0] ) ;
	for( int pos=0;  pos!=-1; pos=ant[pos]  )
		printf("%d ", pos+1 ) ;
	printf("\n" ) ;

	return 0 ;
}


