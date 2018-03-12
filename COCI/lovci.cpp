#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int N ;
int mapa[20][20] ;
int usd[20][20] ;
int dr[] = { -1, -1, 1, 1 } ;
int dc[] = { -1, 1, -1, 1 } ;

int amp( int r, int c, int k ) {
	if(  k  )  {
		int res = 0,  w=-(1<<30) ;
		int i, j, d ;
		for( d=0; d<4; d++ ) {
			i = r+dr[d] ;
			j = c+dc[d] ;
			while(  i>=0  &&  i<N  &&  j>=0  && j<N  )    {
				if( !usd[i][j] ) {
					usd[i][j] = k ;
					res += mapa[i][j] ;
				}
				i += dr[d] ;
				j += dc[d] ;
			}
		}
		for( d=0; d<4; d++ ) {
			i = r+dr[d] ;
			j = c+dc[d] ;
			while(  i>=0  &&  i<N  &&  j>=0  && j<N  )    {
				w = max(  w,  amp(  i,  j,  k-1  )   ) ;
				i += dr[d] ;
				j += dc[d] ;
			}
		}
		for( d=0; d<4; d++ ) {
			i = r+dr[d] ;
			j = c+dc[d] ;
			while(  i>=0  &&  i<N  &&  j>=0  && j<N  )    {
				if( usd[i][j] == k ) {
					usd[i][j] = 0 ;
				}
				i += dr[d] ;
				j += dc[d] ;
			}
		}
		return res+w ;
	}
	else {
		int res = 0 ;
		int i, j, d ;
		for( d=0; d<4; d++ ) {
			i = r+dr[d] ;
			j = c+dc[d] ;
			while(  i>=0  &&  i<N  &&  j>=0  && j<N  )    {
				if( !usd[i][j] ) {
					res += mapa[i][j] ;
				}
				i += dr[d] ;
				j += dc[d] ;
			}
		}
		return res ;
	}
} 

int main() {
	int i, j, K ;
	int res = -(1<<30) ;
	
	scanf("%d%d",&N,&K ) ;
	N*=2 ;
	for( i=0; i<N; i++ )
		for( j=0; j<N; j++ )
			scanf("%d",&mapa[i][j] ) ;
			
	for( i=0; i<=K; i++ ) 
		res = max(  res,   amp( 0, N/2-1, i )  +  amp( 0, N/2, K-i )   )  ;
	printf("%d\n",res ) ;
	
	return 0 ;
}
