#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
const int limG = 11 ;
const int limN = 305 ;

struct est {
	long long ini, fin, tip ;
	est() {
	}
	est( int a, int b, int c ) {
		ini = a ;
		fin = b ;
		tip = c ;
	}
};

bool operator<( est A, est B ) {
	return A.ini < B.ini ;
}

int N, G ;
est juegos[limN] ;
int req[limG], dp[limN][1<<limG] ;

int main() {
	int E ;
	int i, b, j, tmp ;
	int res = 1 ;
	
	memset( req, 0, sizeof(req) ) ;
	memset( dp, 0, sizeof(dp) ) ;
	
	scanf("%d%d%d", &N, &E, &G ) ;
	for( int i=0; i<N; i++ ) {
		cin >> juegos[i].ini >> juegos[i].fin >> juegos[i].tip ;
	}
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		req[a] = req[a] | (1<<b) ;
	}
	
	
	sort( juegos, juegos+N ) ;
	
	for( i=0; i<N; i++ ) {
		dp[i][1<<juegos[i].tip] = 1 ;
				
		for( b=0; b<(1<<G); b++ ) {
			if( (b & req[juegos[i].tip]) == req[juegos[i].tip]  )  {
				if(  ((1<<juegos[i].tip) & b)==0    )   {
					tmp = b - req[juegos[i].tip] ;
					tmp |= (1<<juegos[i].tip) ;
					
					for( j=0; j<i; j++ ) {
						if( juegos[i].ini>juegos[j].fin && dp[j][b]>0 ) {
							dp[i][tmp] = max( dp[i][tmp], dp[j][b] + 1 ) ;
							res = max( dp[i][tmp], res ) ;
						}
					}
				}
			}
		}
		
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
