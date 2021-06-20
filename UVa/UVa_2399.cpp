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
#include <stack>
using namespace std ;
const int lim = 1005 ;

bool muere = 0 ;
int dp[lim][lim] ;
int sigC[lim][26], antC[lim][26] ;

void caso() {
	int N ;
	char S[lim] ;
	int res[lim] ;
	int W=0, K ;

	muere = scanf("%s", S )==EOF ;
	if( muere )
		return ;
	N = strlen(S) ;

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<26; j++ ) {
			antC[i][j] = -1 ;
			if( i )
				antC[i][j] = antC[i-1][j] ;
			if( S[i]==j+'a' )
				antC[i][j] = i ;
		}
	}
	for( int i=N-1; i>=0; i-- ) {
		for( int j=0; j<26; j++ ) {
			sigC[i][j] = N ;
			if( i+1<N )
				sigC[i][j] = sigC[i+1][j] ;
			if( S[i]==j+'a' )
				sigC[i][j] = i ;
		}
	}
	for( int i=N-1; i>=0; i-- ) {
		dp[i][i] = 1 ;
		if( i+1<N ) 
			if( S[i]==S[i+1] ) 
				dp[i][i+1] = 2 ;
			else 
				dp[i][i+1] = 1 ;

		for( int j=i+2; j<N; j++ ) {
			if( S[i]==S[j] )
				dp[i][j] = dp[i+1][j-1]+2 ;
			else
				dp[i][j] = max( dp[i][j-1], dp[i+1][j] ) ;
		}

	}

	K = dp[0][N-1]-1 ;
	for( int ini=0, fin=N-1; ini<=fin; ) {
		int w = 0 ;
		for( int j=0; j<26; j++ ) {
			if( sigC[ini][j]>fin || antC[fin][j]<ini || dp[ sigC[ini][j] ][ antC[fin][j] ]!=dp[ini][fin]  )
				continue ;
			w = j ;
			break ;
		}
		res[W++] = res[K-W] = w + 'a' ;
		ini = sigC[ini][w]+1 ;
		fin = antC[fin][w]-1 ;
	}

	for( int i=0; i<=K; i++ )
		printf("%c", res[i] ) ;
	printf("\n" ) ;
}

int main() {

	while( !muere ) 
		caso() ;

	return 0 ;
}
