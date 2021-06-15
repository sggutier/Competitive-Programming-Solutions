#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int limC = 10004 ;
const int limR = 103 ;

int N, M ;
char arr[limR][limC] ;
int disC[limR][limC] ;

int main() {
	int res = (1<<30) ;
	
	scanf("%d%d", &N, &M ) ;
	for( int i=0; i<N; i++ )
		scanf("%s", arr[i] ) ;
		
	for( int i=0; i<N; i++ ) {
		int ult=-(1<<29) ;
		for( int j=0; j<M; j++ ) {
			if( arr[i][j]=='1' )
				ult = j-M ;
		}
		if( ult==-(1<<29) ) {
			printf("-1\n" ) ;
			return 0 ;
		}		
		for( int j=0; j<M; j++ ) {
			if( arr[i][j]=='1' ) 
				ult = j ;
			disC[i][j] = j-ult ;
		}
		
		ult=(1<<29) ;
		for( int j=M-1; j>=0; j-- ) {
			if( arr[i][j]=='1' )
				ult = j+M ;
		}
		for( int j=M-1; j>=0; j-- ) {
			if( arr[i][j]=='1' ) 
				ult = j ;
			disC[i][j] = min( ult-j, disC[i][j] ) ;
		}
	}
	
	for( int j=0; j<M; j++ ) {
		int carg = 0 ;
		for( int i=0; i<N; i++ ) 
			carg += disC[i][j] ;
		res = min( res, carg ) ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
