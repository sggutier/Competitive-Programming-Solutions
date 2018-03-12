#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000

int N, M ;
char S[lim][lim] ;
int res[10] ;

int main() {	
	scanf("%d%d", &N, &M ) ;
	N = 5*N+1 ;
	M = 5*M+1 ;
	for( int i=0; i<N; i++ )
		scanf("%s", S[i] ) ;
		
	for( int i=1; i<N; i+=5 ) {
		for( int j=1; j<M; j+=5 ) {
			int k = 0 ;
			for( ; k<4 && S[i+k][j]=='*'; k++ ) ;
			res[k] ++ ;
		}
	}
	
	for( int i=0; i<=4; i++ )
		printf("%d ", res[i] ) ;
	printf("\n" ) ;
	
	return 0 ;
}
