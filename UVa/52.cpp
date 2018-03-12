#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int N, M ;
int dp[1000][1000] ;
int sig[1000][1000] ;

int main() {
	//freopen( "52.in" , "r", stdin ) ;
	
	while( scanf("%d%d", &N, &M ) != EOF ) {
		int ren, col ;
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<M; j++ ) {
				scanf("%d", &dp[i][j] ) ;
			}
		}
		for( int j=M-2; j>=0; j-- ) {
			for( int i=0; i<N; i++ ) {
				sig[i][j] = (1<<30) ;
				int w = (1<<30) ;
				for( int k=-1; k<=1; k++  ) {
					if( dp[(i+k+N)%N][j+1]<w   ) {
						w = dp[(i+k+N)%N][j+1] ;
						sig[i][j] = (i+k+N)%N  ;
					}
					else if( dp[(i+k+N)%N][j+1]==w   ) {
						w = dp[(i+k+N)%N][j+1] ;
						sig[i][j] = min(   sig[i][j],  (i+k+N)%N  ) ;
					}
				}
				dp[i][j] += w ;
			}
		}
		ren = 0 ;
		for( int i=0; i<N; i++ ) {
			if( dp[i][0] < dp[ren][0]  ) {
				ren = i ;
			}
		}
		col = ren ;
		for( int j=0; j+1<M; j++  ) {
			printf("%d ", ren+1 ) ;
			ren = sig[ren][j] ;
		}
		printf("%d\n", ren+1 ) ;
		printf("%d\n", dp[col][0] ) ;
	}
	
	return 0 ;
}
