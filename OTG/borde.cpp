#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int N ;
	int fin[8][8], mapa[8][8] ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<N; j++ )
			scanf("%d", &fin[i][j] ) ;
		
	for( int b=0; b<(1<<N); b++ ) {
		int i, j ;
		
		for( i=0; i<N; i++ )
			for( j=0; j<N; j++ )
				mapa[i][j] = 0 ;
				
		for( j=0; j<N; j++ )
			if( (1<<j) & b  )
				mapa[i][j] = 1 ;
		for( i=1; i<N; i++ ) {
			if( mapa[i][j] == 
		}
	}
	
	return 0 ;
}
