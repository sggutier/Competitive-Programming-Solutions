#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
using namespace std ;
const int mod = 1337377 ;
const int limW = 300005 ;
const int limK = 105 ;
const int limN = 4005 ;

int W = 1 ;
int sig[limK*limN][26] ;
bool fin[limK*limN], usd[limW] ;
unsigned int dp[limW] ;
int P ;
char plb[limW] ;

void mete( int N, char S[] ) {
	int pos = 0 ;

	for( int i=0; i<N; i++ ) {
		if( !sig[pos][S[i]-'a'] )
			sig[pos][S[i]-'a'] = W++ ;
		pos = sig[pos][S[i]-'a'] ;
	}

	fin[pos] = 1 ;
}

int main() {
	int N ;
	char tmp[limK] ;

	scanf("%s", plb ) ;
	P = strlen(plb) ;
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", tmp ) ;
		int k = strlen(tmp) ;
		mete( k, tmp ) ;
	}

	for( int i=0; i<P; i++ )
		plb[i] -= 'a' ;

	dp[P] = 1 ;
	for( int i=P-1; i>=0; i-- ) {
		int pos = 0 ;
		for( int j=i; j<P; j++ ) {
			pos = sig[pos][plb[j]] ;
			if( !pos )
				break ;
			if( fin[pos] )
				dp[i] = (dp[i]+dp[j+1])%mod ;
		}
	}

	printf("%d\n", dp[0] ) ;

	return 0 ;
}

