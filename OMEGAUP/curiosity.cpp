#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std ;
const int lim = 1005 ;
#define par pair<int,int>
#define r first
#define c second

int R, C, K ;
int minP[lim][lim] ;
int dr[lim], dc[lim] ;
queue <par> Q ;

int main() {
	par ini, fin ;
	
	scanf("%d%d%d", &R, &C, &K ) ;
	scanf("%d%d", &ini.r, &ini.c ) ;
	scanf("%d%d", &fin.r, &fin.c ) ;
	for( int i=0; i<K; i++ ) 
		scanf("%d%d", &dr[i], &dc[i] ) ;
		
	ini.r -- ;
	ini.c -- ;
	fin.r -- ;
	fin.c -- ;
	Q.push( ini ) ;
	minP[ini.r][ini.c] = 1 ;
	while( !Q.empty() ) {
		par pos = Q.front(), tmp ;
		Q.pop() ;
		
		for( int i=0; i<K; i++ ) {
			tmp.r = pos.r + dr[i] ;
			tmp.c = pos.c + dc[i] ;
			if( tmp.r<0 || tmp.r>=R || tmp.c<0 || tmp.c>=C || minP[tmp.r][tmp.c] )
				continue ;
			minP[tmp.r][tmp.c] = minP[pos.r][pos.c] +1 ;
			Q.push(tmp) ;
		}
	}
	
	printf("%d\n", minP[fin.r][fin.c]-1 ) ;
	
	return 0 ;
}
