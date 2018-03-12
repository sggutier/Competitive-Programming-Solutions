#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 15

int N ;
int mat[lim][lim] ;
int dp[lim][1<<lim], usd[lim][1<<lim] ;

int memo( int pos, int masc ) {
	if( pos==N )
		return 1 ;
	if( usd[pos][masc] )
		return dp[pos][masc] ;
	usd[pos][masc] = 1 ;
	for( int i=0, w=1; i<N; i++ )
		if( ((1<<i) & masc)==0  ) {
			dp[pos][masc] += mat[i][pos]*memo(pos+1, masc | (1<<i)  )*w ;
			w *= -1 ;
		}
	return dp[pos][masc] ;
}

int main() {
	int w ;
	
	w = scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<N; j++ )
			w = scanf("%d", &mat[i][j] ) ;
			
	printf("%d\n", memo( 0, 0 ) ) ;
	
	return 0 ;
}
