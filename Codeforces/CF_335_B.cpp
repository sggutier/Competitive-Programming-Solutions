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
#include <vector>
using namespace std ;
const int lim = 50005 ;

int N ;
char S[lim] ;
vector <int> let[26] ;
int sig[lim][101], dp[lim][101] ;

int buscaSig( int W, int K ) {
	int ini=0, fin=let[K].size()-1 ;

	while( ini<fin ) {
		int piv = (ini+fin)/2 ;
		if( let[K][piv] <= W )
			ini = piv+1 ;
		else
			fin = piv ;
	}

	if( let[K][ini]>W )
		return let[K][ini] ;
	return N ;
}

int main() {
	char res[105] ;

	scanf("%s", S ) ;
	N = strlen(S ) ;

	for( int i=0; i<N; i++ )
		let[S[i]-'a'].push_back(i) ;

	for( int i=N-1; i>=0; i-- ) {
		dp[i][1] = i ;
		dp[i][2] = buscaSig( i+1, S[i] ) ;
		for( int j=3; j<=100; j++ ) {
			dp[i][j] = N ;
			if( i+1<N ) {
				dp[i][j] = dp[i+1][j] ;
				sig[i][j] = 1 ;
			}
			if(  buscaSig( dp[i+1][j-2], S[i] ) < dp[i][j] ) {
				dp[i][j] = buscaSig( dp[i+1][j-2], S[i] ) ;
				sig[i][j] = 2 ;
			}
		}
	}

	for( int j=100; j>0; j-- ) {
		if( dp[0][j]==N )
			continue ;
		int x=0, y=j-1, i=0, k=j ;

		while( ini<=fin ) {
			if( sig[i][j]==1 ) {
				i ++ ;
			}
			else {
				res[x++] = S[i] ;
				res[y--] = S[i] ;
				i ++ ;
				j -= 2 ;
			}
		}

		printf("%s\n", res ) ;

		break ;
	}

	return 0 ;
}


