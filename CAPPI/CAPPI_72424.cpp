#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std ;
#define lim 50


struct coor {
	int r, c, l ;
	coor() {
	}
	coor( int x, int y, int z ) {
		r = x ;
		c = y ;
		l = z ;
	}
};

int N ;
int mapa[lim][lim][2] ;
int minP[lim][lim][2] ;
queue <coor> Q[3*lim] ;

int main() {
	char S[lim] ;
	int res = (1<<30) ;
	
	scanf("%d", &N ) ;
	for( int i=0; i+1<N; i++ ) {
		scanf("%s", S  ) ;
		for( int j=0; j<N; j++ ) {
			int a ;
			a = S[j]-'0' ;
			mapa[i][j][1] = a ;
			mapa[i+1][j][0] = a ;
		}
	}
	
	for( int i=0; i<N; i++ ) 
		Q[0].push( coor(i,0,1)  )  ;
	
	for( int x=0; x<=3*N; x++ ) {
		while( !Q[x].empty()  )  {
			coor pos = Q[x].front() ;
			Q[x].pop() ;
			if( minP[pos.r][pos.c][pos.l] ) 
				continue ;
				
			//printf("%d %d %d -> %d\n", pos.r, pos.c, pos.l, x ) ;
			minP[pos.r][pos.c][pos.l] = x+1 ;
				
			if( pos.c >= N ) {
				res = min( res, x ) ;
				continue ;
			}
			
			/*if( mapa[pos.r][pos.c][0]   )  
				Q[x].push( coor( pos.r-1, pos.c, 0 )    )  ;
			if( mapa[pos.r][pos.c][1]   )  
				Q[x].push( coor( pos.r+1, pos.c, 0 )    )  ;*/
			
			/*if( mapa[pos.r][pos.c][0]  )  
				Q[x+1].push( coor(pos.r, pos.c+1, 1 )  )  ;
			else if( pos.l ) 
				Q[x+2].push( coor(pos.r, pos.c+1, 1 )  )  ;
			else if( mapa[pos.r][pos.c][1]  )  
				Q[x+3].push( coor(pos.r, pos.c+1, 1 )  )  ;*/
				
			if( mapa[pos.r][pos.c][0]  ||   mapa[pos.r][pos.c][1]  )  
				Q[x+1].push( coor(pos.r, pos.c+1, 1 )  )  ;
			else if( pos.l ) 
				Q[x+2].push( coor(pos.r, pos.c+1, 1 )  )  ;
		}
		
	}
	
	
	cout << res << endl ;
	
	return 0 ;
}

