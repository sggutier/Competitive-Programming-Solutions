#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std ;
#define lim 10005

int sig[lim][26] ;
bool dict[26] ;

string A, B ;

int main() {
	int i, j ;
	int N, M ;
	int ult = 0, res = 1 ;
	
	for( i=0; i<lim; i++ )
		for( j=0; j<26; j++ )
			sig[i][j] = -1 ;
			
	cin >> A >> B ;
	N = A.size() ;
	M = B.size() ;
	
	for( i=0; i<N; i++ )
		dict[ A[i]-'a' ] = 1 ;
	for( i=N-1; i>=0; i-- ) {
		for( j=0; j<26; j++ )
			sig[i][j] = sig[i+1][j] ;
		sig[i][ A[i]-'a' ] = i ;
	}
		
	for( i=0; i<M; i++, ult++ ) {
		if( !dict[ B[i]-'a' ] ) {
			printf("-1\n" ) ;
			return 0 ;
		}
		if( sig[ult][ B[i]-'a' ] == -1 ) {
			ult = 0 ;
			res ++ ;
		}
		ult = sig[ult][ B[i]-'a' ] ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
