#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define mucho 50000
#define lim 402

int N, A=0, B=0 ;
int X=0, Y=0 ;
int dp[lim][lim][lim] ;
char usd[lim][lim][lim] ;
int sup[lim], inf[lim] ;

int memo( int k, int i, int j  )   {
	if( k==N  )
		return 0 ;
	if( usd[k][i][j]  )  
		return dp[k][i][j]  ;
		
	usd[k][i][j] = 1 ;
	dp[k][i][j] = -mucho ;
	
	if( k-i<A && k-j<B  )   {
		dp[k][i][j] = max( dp[k][i][j],
						   memo(k+1,i,j) +  sup[k-i]*inf[k-j]    )  ;
	}
	if( k-i<A &&  j<Y  )   {
		dp[k][i][j] = max( dp[k][i][j],
						   memo(k+1,i,j+1)  )  ;
	}
	if( i<X &&  k-j<B  )   {
		dp[k][i][j] = max( dp[k][i][j],
						   memo(k+1,i+1,j)  )  ;
	}
	if( i<X && j<Y  )  {
		dp[k][i][j] = max( dp[k][i][j],
						   memo(k+1,i+1,j+1)  )  ;
	}
	
	return dp[k][i][j] ;
}

int main() {
	int a ;
	int i, j, k ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &a ) ;
		if( a )
			sup[A++] = a ;
		else
			X ++ ;
	}
	for( int i=0; i<N; i++ ) {
		scanf("%d", &a ) ;
		if( a )
			inf[B++] = a ;
		else
			Y ++ ;
	}		
		
	if( X==N || Y==N   )  
		printf("0\n" ) ;
	else {
		printf("%d\n", memo( 0, 0, 0 )   )  ;
	}
	
	return 0 ;
}
