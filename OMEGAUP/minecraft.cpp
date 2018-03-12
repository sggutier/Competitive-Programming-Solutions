#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std; 
#define par pair<int,int>
#define r first
#define c second
const int lim = 505 ;

int N, M ;
char mapa[lim][lim] ;
int minP[lim][lim] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;
priority_queue <par> Q ;

int main() {	
	par ini, fin ;
	
	scanf("%d%d", &N, &M ) ;
	scanf("%d%d", &ini.r, &ini.c ) ;
	scanf("%d%d", &fin.r, &fin.c ) ;
	for( int i=0; i<N; i++ )
		scanf("%s", mapa[i] ) ;
	
	ini.r -- ;
	ini.c -- ;
	fin.r -- ;
	fin.c -- ;
	Q.push( par( -1, ini.r*M + ini.c )   ) ;
	
	while( !Q.empty() ) {
		par tmp, pos ;
		int T ;
		tmp = Q.top() ;
		Q.pop() ;
		pos = par( tmp.c/M, tmp.c%M ) ;
		T = -tmp.r ;
		if( minP[pos.r][pos.c] )
			continue ;
			
		minP[pos.r][pos.c] = T ;
		T ++ ;
		
		for( int d=0; d<4; d++ ) {
			par pos2 = par( pos.r + dr[d], pos.c + dc[d] ) ;
			if( pos2.r<0 || pos2.r>=N || pos2.c<0 || pos2.c>=M || minP[pos2.r][pos2.c] || mapa[pos2.r][pos2.c]=='#' )
				continue ;
			if( mapa[pos2.r][pos2.c]=='.' )
				Q.push( par( -T, pos2.r*M + pos2.c )   ) ;
			else
				Q.push( par( -T - mapa[pos2.r][pos2.c] + '0' , pos2.r*M + pos2.c )   ) ;
		}
	}
	
	printf("%d\n", minP[fin.r][fin.c] -1 ) ;
	
	return 0 ;
}
