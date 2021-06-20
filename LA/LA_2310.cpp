#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int mod = 98765431 ;
const int lim = 15 ;
const int limB = 1<<lim ;
//aoesunhaoesu

int N ;
int adj[lim][lim] ;
int ant[lim], sig[lim] ;
int dp[lim][limB], maxW[lim][limB] ;
queue <int> Q, Q2 ;

void caso() {
	int K, res=0 ;
	int ini ;

	memset( dp, 0, sizeof(dp) ) ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) 
			scanf("%d", &adj[i][j] ) ;
		ant[i] = 0 ;
		sig[i] = 1000 ;
	}
	scanf("%d", &K ) ;
	for( int i=0; i<K; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		ant[tmp] = i ;
		sig[tmp] = i ;
		if( !i ) {
			ini = tmp ;
			dp[tmp][1<<tmp] = 1 ;
			maxW[tmp][1<<tmp] = 0 ;
			Q.push(tmp) ;
			Q2.push(1<<tmp) ;
		}
	}

	//for( int i=0; i<N; i++ )
		//printf("%d %d\n", ant[i], sig[i] ) ;
	//cout << ini << endl ;

	while( !Q.empty() ) {
		int pos=Q.front(), msk=Q2.front(); 
		Q.pop() ;
		Q2.pop() ;

		//printf("%d %d -> %d\n", pos, msk, dp[pos][msk] ) ;

		if( msk==(1<<N)-1 ) {
			if( adj[pos][ini] )
				res = (res+dp[pos][msk])%mod ;
		}
		else {
			for( int i=0; i<N; i++ ) {
				if( adj[pos][i] && ((1<<i)&msk)==0 && maxW[pos][msk]<sig[i] ) {
					//printf("    %d %d -> %d\n", i, msk | (1<<i), dp[i][msk | (1<<i)] ) ;
					if( !dp[i][ msk | (1<<i) ] ) {
						Q.push(i) ;
						Q2.push( msk | (1<<i) ) ;
						maxW[i][ msk | (1<<i) ] = max( maxW[pos][msk], ant[i] ) ;
					}
					dp[i][ msk | (1<<i) ] = (dp[i][msk | (1<<i)] + dp[pos][msk] ) % mod ;
				}
			}
		}
		//getchar() ;
	}

	printf("%d\n", res ) ;

}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) 
		caso() ;

	return 0 ;
}

