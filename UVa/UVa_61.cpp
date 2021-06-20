#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 1005
#define inf (1<<29)

int E, N ;
int adj[lim][2] ;
int dp[lim][lim], dp2[lim][lim], res[lim][lim] ;

void caso( int T ) {
	N = 0 ;
	for( int i=0; i<E; i++ ) {
		scanf("%d%d", &adj[i][0], &adj[i][1] ) ;
		N = max( N, adj[i][0] ) ;
		N = max( N, adj[i][1] ) ;
	}
	N ++ ;
	
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			dp[i][j] = 0 ;
			res[i][j] = 0 ;
		}
		dp[i][i] = 1 ;
	}
	for( int k=1; k<N; k++  )  {		
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<N; j++ ) {
				dp2[i][j] = 0 ;
			}
		}
		for( int i=0; i<N; i++ ) {
			for( int e=0; e<E; e++  ) {
				dp2[i][ adj[e][1] ] += dp[i][ adj[e][0] ] ;
				dp2[i][ adj[e][1] ] = min( dp2[i][ adj[e][1] ], inf  )  ;
			}
		}
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<N; j++ ) {
				dp[i][j] = dp2[i][j] ;
				res[i][j] += dp[i][j] ;
				res[i][j] = min( res[i][j], inf ) ;
			}
		}
	}
	for( int k=0; k<N; k++ ) {
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<N; j++ ) {
				dp2[i][j] = 0 ;
			}
		}
		for( int i=0; i<N; i++ ) {
			for( int e=0; e<E; e++  ) {
				if(  dp[i][ adj[e][0] ]   )
					dp2[i][ adj[e][1] ] = inf ;
			}
		}
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<N; j++ ) {
				dp[i][j] = dp2[i][j] ;
				res[i][j] += dp[i][j] ;
				res[i][j] = min( res[i][j], inf ) ;
			}
		}
	}
	
	printf("matrix for city %d\n", T ) ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++  ) {
			if( j )
				printf(" " ) ;
			if( res[i][j] == inf  )
				printf("-1" ) ;
			else
				printf("%d", res[i][j] ) ;
		}
		printf("\n" ) ;
	}
	return ;
}

int main() {
	
	int T = 0 ;
	while( scanf("%d",&E)  !=  EOF   )   {
		caso( T ) ;
		T ++ ;
	}
	return 0 ;
}
