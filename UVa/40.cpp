#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
#define lim 25

	//	 dest  pos  usd
long double dp[lim][lim][lim] ;
int sig[lim][lim][lim] ;
int N ;
long double mapa[lim][lim] ;

long double memo( int pos, int dest, int usd ) {
	
	if( sig[pos][dest][usd] != -2  )  {
		return dp[pos][dest][usd] ;
	}
	sig[pos][dest][usd] = -1 ;
	if( pos==dest ) 
		dp[pos][dest][usd] = 1.0 ;
	else
		dp[pos][dest][usd] = 1.0*0 ;
	if( usd==N ) {
		return dp[pos][dest][usd] ;
	}
	
	for( int j=0; j<N; j++ ) {
		if( j==pos )
			continue ;
		long double a = memo(j,dest,usd+1)*mapa[pos][j] ;
		if( a>dp[pos][dest][usd]   )  {
			dp[pos][dest][usd] = a ;
			sig[pos][dest][usd] = j ;
		}
	}
	
	
	return dp[pos][dest][usd] ;
}

void sol() {
	int res = -1 ;
	
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			if( j==i )
				mapa[i][j] = 1.0 ;
			else
				cin >> mapa[i][j]  ;
		}
	}
	
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			for( int k=0; k<N; k++ ) {
				dp[i][j][k] = -1.0 ;
				sig[i][j][k] = -2 ;
			}
		}
	}
	
	for( int i=0; i<N; i++ ) {
		if( memo(i,i,0)>=1.01  ) {
			res = i ;
			break ;
		}
	}
	
	if( res==-1 ) {
		printf("no arbitrage sequence exists\n" ) ;
	}
	else {
		int pos = res, usd=0 ;
		while( sig[pos][res][usd]!=-1  ) {
			printf("%d " , pos+1 ) ;
			pos = sig[pos][res][usd] ;
			usd ++ ;
		} 
		printf("%d\n", pos+1 ) ;
	}
}

int main() {
	while( scanf("%d", &N ) != EOF  )  {
		sol() ;
	}
	
	return 0 ;
}

