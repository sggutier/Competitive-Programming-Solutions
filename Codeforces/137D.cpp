#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;
#define lim 505

int dp[lim][lim] ;
int pal[lim][lim] ;
int sig[lim][lim] ;

int main() {
	string S ;
	int K, N ;
	int i, j, a, b, w ;
	
	cin >> S ;
	cin >> K ;
	N = S.size() ;
	
	for( i=0; i<N; i++ ) {
		for( j=i; j<N; j++ ) {
			w = 0 ;
			for( a=i, b=j; a<b; a++, b-- ) {
				if( S[a] != S[b]  )
					 w ++ ;
			}
			pal[i][j] = w ;
		}
	}
	
	for( i=0; i<=K; i++ )
		dp[N][i] = (1<<30) ;
	dp[N][0] = 0 ;
	
	for( i=N-1; i>=0; i-- ) {
		dp[i][0] = (1<<30) ;
		for( j=1; j<=K; j++ ) {
		
			dp[i][j] = dp[i][j-1] ;
			sig[i][j] = sig[i][j-1] ;
			for( w=i; w<N; w++ ) {
				if(    dp[i][j]  > dp[w+1][j-1]  +  pal[i][w]   ) {
					dp[i][j] = dp[w+1][j-1]  +  pal[i][w] ;
					sig[i][j] = w ;
				}
			}
			
		}
	}
	
	printf("%d\n", dp[0][K]  )  ;
	for( int pos=0, x=K; pos<N; pos=sig[pos][x]+1,  x--    )   {
		for( a=pos, b=sig[pos][x];   a<b;  a++, b--   )  
			S[a] = S[b] ;
		if( pos )
			printf("+" ) ;
		for( i=pos; i<=sig[pos][x];  i++  )
			printf("%c", S[i] ) ;
	}
	printf("\n" ) ;
	

	return 0 ;
}
