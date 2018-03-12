#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 15 ;
const int limB = 1<<lim ;
const int inf = 1<<30 ;

int N, K ;
int B ;
int res = -inf ;
int dp[limB][lim][lim], arr[lim][lim] ;
int susu[lim][lim][lim] ;
int grd[lim][lim] ;

int main() {
	freopen( "partition.in", "r", stdin ) ;
	freopen( "partition.out", "w", stdout ) ;

	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<N; j++ ) 
			scanf("%d", &arr[i][j] ) ;
	B = (1<<(N-1) ) ;

	for( int i=0; i<N; i++ ) {
		for( int a=0; a<N; a++ ) {
			for( int b=a; b<N; b++ ) {
				susu[i][a][b] = arr[i][b] ;
				if( b>a )
					susu[i][a][b] += susu[i][a][b-1] ;
			}
		}
	}

	for( int b=0; b<B; b++ ) {

		memset( grd, 0, sizeof(grd) ) ;

		for( int x=0, y; x<N; x=y+1 ) {
			for( y=x; x<N-1 && ((1<<x) & b)==0; y++ ) ;

			for( int i=0; i<N; i++ ) {
				for( int j=i, tmp; j<N; j++ ) {
					tmp += susu[j][x][y] ;
					grd[i][j] = max( grd[i][j], tmp ) ;
				}
			}
		}

		for( int i=0; i<N; i++ ) {
			for( int k=0; k<=N; k++ )
				dp[b][i][k] = inf ;
			for( int j=i; j<N; j++ ) {
				for( int k=N-j; k<=N; k++ ) {
					dp[b][i][k] = min( dp[b][i][k], dp[b][j+1][k-1] + grd[i][j] ) ;
				}
			}
		}

	}

	return 0 ;
}


