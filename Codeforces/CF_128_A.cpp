#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N = 8 ;
	char S[10][10] ;
	int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 } ;
	int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 } ;
	
	for( int i=0; i<N; i++ )
		scanf("%s", S[i] ) ;
	S[0][N-1] = '.' ;
		
	for( int w=0; w<30; w++ ) {
		for( int i=0; i<N; i++ ) {
			for( int j=0; j<N; j++ ) {	
				if( S[i][j] == 'M' ) {
					for( int d=0; d<8; d++ ) {
						int r=i+dr[d], c=j+dc[d]; 
						if( r>=0 && r<N && c>=0 && c<N && S[r][c]=='.' ) {
							S[r][c] = 'm' ;
						}
					}
				}
			}
		}
		
		for( int i=N-1; i>=0; i-- ) {
			for( int j=0; j<N; j++ ) {
				if( S[i][j]=='m' )
					S[i][j] = 'M' ;
				if( S[i][j]=='S' ) {
					S[i+1][j] = 'S' ;
					S[i][j] = '.' ;
				}
			}
		}
	}
	
	if( S[0][N-1]=='M' )
		printf("WIN\n"  ) ;
	else
		printf("LOSE\n" ) ;
	
	return 0 ;
}
