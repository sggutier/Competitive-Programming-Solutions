#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int N, M, A, B ;
	char arr[105][105] ;
	
	scanf("%d%d%d%d",&N,&M,&A,&B ) ;
	
	for( int i=0, col=0; i<N; i++, col=(col+1)%2 ) {
		int w = col ;
		for( int j=0; j<M; j++, w=(w+1)%2 ) {
			for( int r=0; r<A; r++ ) {
				for( int c=0; c<B; c++ ) {
					if( w==0 )
						arr[i*A+r][j*B+c] = 'X' ;
					else
						arr[i*A+r][j*B+c] = '.' ;
				}
			}
		}
	}
	
	for( int i=0; i<N*A; i++ )
		printf("%s\n", arr[i] ) ;
	
	return 0 ;
}
