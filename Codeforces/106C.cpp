#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10000

int K, N ;
int cost[lim][4] ;
int dp[lim] ;

void lee() ;
void soluciona() ;
void imprime() ;

int main() {
	
	lee() ;
	soluciona() ;
	imprime() ;
	
	return 0 ;
}

void imprime() {
	printf("%d\n", dp[K] ) ;
}

void lee() {
	scanf("%d%d", &K, &N ) ;
	scanf("%d%d", &cost[N][2], &cost[N][3]  ) ;
	for( int i=0; i<N; i++ ) 
		for( int j=0; j<4; j++ )
			scanf("%d", &cost[i][j] ) ;
	N ++ ;
}

void soluciona() {
	for( int i=0; i<N; i++ ) {
		for( int j=K; j>=0; j-- ) {
			for( int a=1; a*cost[i][1]<=cost[i][0] && a*cost[i][2]<=j; a++ ) {
				dp[j] = max( dp[j], dp[j-a*cost[i][2]] + a*cost[i][3] ) ;
			}
		}
	}
}
