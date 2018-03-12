#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define limN 2005
#define limQ 4000005
typedef pair <int,int> par ;
#define x first
#define y second

struct cola {
	par arr[limQ] ;
	int ini, fin ;
	cola() {
		ini = 0, fin=0 ;
	}
	par front() {
		return arr[ini] ;
	}
	void pop() {
		ini ++ ;
	}
	bool empty() {
		return ini == fin ;
	}
	void push( par A ) {
		arr[fin++] = A ;
	}
} ;

cola Q ;
bool usd[limN][limN] ;

int main() {
	freopen( "input.txt", "r", stdin ) ;
	freopen( "output.txt", "w", stdout ) ;
	
	int N, M ;
	int K ;
	int i, j, d ;
	int dx[] = { -1, 0, 1, 0 } ;
	int dy[] = { 0, 1, 0, -1 } ;
	par pos, pos2 ;
	
	scanf("%d%d", &N, &M ) ;
	scanf("%d", &K ) ;
	for( i=0; i<K; i++ ) {
		scanf("%d%d", &pos.x, &pos.y ) ;
		pos.x -- ;
		pos.y -- ;
		Q.push( pos ) ;
		usd[pos.x][pos.y] = 1 ;
	}
	
	while( !Q.empty() ) {
		pos = Q.front() ;
		Q.pop() ;
		for( d=0; d<4; d++ ) {
			pos2 = pos ;
			pos2.x += dx[d] ;
			pos2.y += dy[d] ;
			if( pos2.x < 0 || pos2.y < 0 || pos2.x >= N || pos2.y >= M  )
				continue ;
			if( usd[pos2.x][pos2.y] )
				continue ;
			usd[pos2.x][pos2.y] = 1 ;
			Q.push( pos2 ) ;
		}
	}
	
	printf("%d %d\n", pos.x +1, pos.y +1 ) ;
	
	return 0 ;
}
