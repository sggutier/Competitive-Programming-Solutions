#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define inf (1<<30)

int main() {
	int N ;
	int prop[1000][4] ;
	int res = inf ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<4; j++ )
			scanf("%d", &prop[i][j] ) ;
	}
	
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			int k ;
			for( k=0; k<3 && prop[i][k]<prop[j][k]; k++ ) ;
			if( k==3 )
				prop[i][3] = inf ;
		}
		res = min( res, prop[i][3] ) ;
	}
	
	for( int i=0; i<N; i++ ) {
		if( res == prop[i][3] ) {
			printf("%d\n", i+1 ) ;
			break ;
		}
	}
}
