#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define limN 20
#define limK 1007 

int N,  W ;
int len[limN] ;
char S[limN][limN] ;
int dp[limN][limN][limK] ;
int T=0 ;
int trie[limN*limN][3] ;
int fin[limN*limN] ;
int U=0 ;
int uber[limN*limN*limN][3] ;
int clas[limN*limN*limN] ;

int main() {
	freopen( "combos.in", "r", stdin ) ;
	freopen( "combos.out", "w", stdout ) ;
	
	char tmp[limN] ;
	int sigT, sigS ;
	int i, j, k, x, y, pos ;
	
	for( int i=0; i<limN*limN; i++ )
		clas[i] = -1 ;
	
	scanf("%d%d", &N, &W ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", S[i] ) ;
		len[i] = strlen( S[i] ) ;
		
		for( j=len[i]-1, pos=0; j>=0; j-- ) {
			if( !trie[pos][S[i][j]-'A']  )
				trie[pos][S[i][j]-'A'] = ++T ;
			pos = trie[pos][S[i][j]-'A'] ;
		}
		fin[pos] ++ ;
		
		for( k=len[i]-2; k>=0; k-- ) {
			for( j=k, pos=0; j>=0; j-- ) {				
				if( !uber[pos][S[i][j]-'A']  )
					uber[pos][S[i][j]-'A'] = ++U ;
				pos = uber[pos][S[i][j]-'A'] ;
			}
			clas[pos] = i ;
		}
	}
	
	for( int k=0; k<=W; k++ ) {
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<len[i]; j++ ) 
				dp[i][j][k] = -1 ;
		}
	}
	dp[0][0][0] = 0 ;
			
	for(  k=0; k<W; k++ ) {
		for(  i=0; i<N; i++ ) {
			for(  j=0; j<len[i]; tmp[j]=S[i][j], j++ ) {	
				
				if( dp[i][j][k]==-1 )
					continue ;
				
				for( tmp[j]='A'; tmp[j]<'D'; tmp[j]++ ) {
					sigT = 0 ;
					sigS = 0 ;
					x = dp[i][j][k] ;
					for(  y=j, pos=0; y>=0; y-- ) {
						if( !trie[pos][tmp[y]-'A']  )
							break ;
						pos = trie[pos][tmp[y]-'A'] ;
						x += fin[pos] ;
					}
					for(  y=j, pos=0; y>=0; y-- ) {
						if( !uber[pos][tmp[y]-'A'] )
							break ;
						pos = uber[pos][tmp[y]-'A'] ;
						if( clas[pos] != -1 ) {
							sigT = clas[pos] ;
							sigS = j-y+1 ;
						}
					}
					
					dp[sigT][sigS][k+1] = max( x, dp[sigT][sigS][k+1] ) ;
				}
				
			}
		}
	}
	
	x = 0 ;
	for( i=0; i<N; i++ ) 
		for( j=0; j<len[i]; j++ )
			x = max( x, dp[i][j][W] ) ;
			
	printf("%d\n", x ) ;
	
	return 0 ;
}
