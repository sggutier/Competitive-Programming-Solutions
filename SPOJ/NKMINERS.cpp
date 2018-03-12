#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 100005
#define inf (1<<30)

int main() {
	int N ;
	char S[lim] ;
	int dp[4][4][4][4], cp[4][4][4][4] ;
	int b ;
	int res = 0 ;
	
	for( int a=0; a<4; a++ ) {
		for( int b=0; b<4; b++ ) {
			for( int c=0; c<4; c++ ) {
				for( int d=0; d<4; d++ ) {
					dp[a][b][c][d] = -inf ;
					cp[a][b][c][d] = -inf ;
				}
			}
		}
	}
	
	
	scanf("%d", &N ) ;
	scanf("%s", S ) ;
	
	dp[0][0][0][0] = 0 ;
	for( int i=0; i<N; i++ ) {
		int w ;
		
		if( S[i] == 'F' ) 
			w = 1 ;
		else if( S[i] == 'B' )
			w = 2 ;
		else
			w = 3 ;
		
		for( int penL=0; penL<4; penL++ ) {
			for( int penR=0; penR<4; penR++ ) {
				for( int ultL=min(penL,1); ultL<4; ultL++ ) {
					for( int ultR=min(penR,1); ultR<4; ultR++ ) {
						if( dp[ultL][ultR][penL][penR] == -inf )	
							continue ;
							
						
						b = (1<<(w-1)) ;
						if( ultL )
							b |= (1<<(ultL-1)) ;
						if( penL )
							b |= (1<<(penL-1)) ;
						if(  b == 7 ) 
							cp[w][ultR][ultL][penR] =   max( dp[ultL][ultR][penL][penR] +3, cp[w][ultR][ultL][penR]   ) ;
						else if(  b>2 && b!=4 ) 
							cp[w][ultR][ultL][penR] =   max( dp[ultL][ultR][penL][penR] +2, cp[w][ultR][ultL][penR]   ) ;
						else 
							cp[w][ultR][ultL][penR] =   max( dp[ultL][ultR][penL][penR] +1, cp[w][ultR][ultL][penR]   ) ;
						
						b = (1<<(w-1)) ;
						if( ultR )
							b |= (1<<(ultR-1)) ;
						if( penR )
							b |= (1<<(penR-1)) ;
						if(  b == 7 ) 
							cp[ultL][w][penL][ultR] =   max( dp[ultL][ultR][penL][penR] +3, cp[ultL][w][penL][ultR]   ) ;
						else if(  b>2 && b!=4 ) 
							cp[ultL][w][penL][ultR] =   max( dp[ultL][ultR][penL][penR] +2, cp[ultL][w][penL][ultR]   ) ;
						else 
							cp[ultL][w][penL][ultR] =   max( dp[ultL][ultR][penL][penR] +1, cp[ultL][w][penL][ultR]   ) ;
					}
				}
			}
		}
		
		for( int penL=0; penL<4; penL++ ) {
			for( int penR=0; penR<4; penR++ ) {
				for( int ultL=min(penL,1); ultL<4; ultL++ ) {
					for( int ultR=min(penR,1); ultR<4; ultR++ ) {
						dp[ultL][ultR][penL][penR] = cp[ultL][ultR][penL][penR] ;
						cp[ultL][ultR][penL][penR] = -inf ;
					}
				}
			}
		}
	}
	
	
	for( int penL=0; penL<4; penL++ ) 
		for( int penR=0; penR<4; penR++ ) 
			for( int ultL=min(penL,1); ultL<4; ultL++ ) 
				for( int ultR=min(penR,1); ultR<4; ultR++ ) 
					res = max( res, dp[ultL][ultR][penL][penR]   ) 	;
					
	printf("%d\n", res ) ;
	
	return 0 ;
}

