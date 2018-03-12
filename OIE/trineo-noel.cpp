#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define limN 1005
#define limW 6
#define f first
#define s second

int N ;
char casas[limN][6] ;
bool usd[limN] ;
int camM[limN] ;
int dis[limN][limN] ;

int calcDis( int a, int b ) {
	int res = 0, z ;
	for( int i=0; i<4; i++ ) {
		z = abs(casas[a][i] - casas[b][i] ) ;
		res += min( z, 26-z ) ;
	}
	return res ;
}

int minP() {
	int res = 0 ;
	int sig, menSig ;
	priority_queue <par> Q ;
	
	for( int i=0; i<N; i++ ) {
		camM[i] = (1<<30) ;
		if( !usd[i] )
			continue ;
		Q.push( par(0, i) ) ;
		usd[i] = 0 ;
		camM[i] = 0 ;
	}
	
	while( !Q.empty() ) {
		sig = Q.top().s ;
		menSig = -Q.top().f ;
		Q.pop() ;
		if( usd[sig] )
			continue ;
		
		res += menSig ;
		usd[sig] = 1 ;
		for( int a=0; a<N; a++ ) {
			if( usd[a] )
				continue ;
			if( dis[a][sig]<camM[a] ) {
				camM[a] = dis[a][sig] ;
				Q.push( par(-dis[a][sig], a)  ) ;
			}
		}
	}
	
	return res ;
}

int caso() {
	int res = (1<<30) ;
	
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ )
			dis[i][j] = calcDis( i, j ) ;
	}
	
	for( int i=0; i<N; i++ ) {
		res = min( res, calcDis(i,limN-1) ) ;
	}
	
	memset( usd, 0, sizeof(usd) ) ;
	usd[0] = 1 ;
	return res + minP() ;
}

int main() {
	casas[limN-1][0] = 'N' ;
	casas[limN-1][1] = 'O' ;
	casas[limN-1][2] = 'E' ;
	casas[limN-1][3] = 'L' ;
	
	while( scanf("%d", &N) != EOF ) {
		int q ;
		for( int i=0; i<N; i++ )
			q = scanf( "%s", casas[i] ) ;
		printf("%d\n", caso() ) ;
	}
	
	return 0 ;
}
