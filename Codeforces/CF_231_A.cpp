#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int N ;
int arr[10000][3] ;

int main() {
	int res = 0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<3; j++ )
			scanf("%d", &arr[i][j] ) ;
			
	for( int i=0; i<N; i++ ) {
		int carg = 0 ;
		for( int j=0; j<3; j++ )
			if( arr[i][j] )
				carg ++ ;
		if( carg >= 2  )
			res ++ ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
