#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 2005

bool pal[lim][lim] ;
long long carg[lim] ;

int main() {
	int N ;
	char S[lim] ;
	long long res = 0LL ;
	
	scanf("%s", S ) ;
	N = strlen(S) ;
	
	for( int i=N-1; i>=0; i-- ) {
		carg[i] = carg[i+1]+1 ;
		res += carg[i+1] ;
		pal[i][i] = 1 ;
		if( S[i]==S[i+1] ) {
			carg[i] ++ ;
			pal[i][i+1] = 1 ;
			res += carg[i+2] ;
		}
		for( int j=i+2; j<N; j++ ) {
			if( S[i]==S[j] && pal[i+1][j-1] ) {
				pal[i][j] = 1 ;
				carg[i] ++ ;
				res += carg[j+1] ;
			}
		}
	}
	
	cout << res << endl ;
	
	return 0 ;
}
