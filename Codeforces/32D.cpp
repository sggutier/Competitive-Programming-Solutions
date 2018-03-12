#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 305

int main() {
	int n, m, k ;
	char mapa[lim][lim] ;
	
	scanf("%d%d%d", &n, &m, &k ) ;
	for( int i=0; i<n; i++ ) 
		scanf("%s", mapa[i] ) ;
	
	for( int r=1; r<n; r++ ) {
		for( int i=r; i+r<n; i++ ) {
			for( int j=r; j+r<m; j++ ) {
				if( mapa[i][j] == '*' && mapa[i+r][j] == '*' && mapa[i-r][j] == '*' && mapa[i][j+r] == '*' && mapa[i][j-r] == '*'  ) {
					k -- ;
					if( k==0 ) {
						printf("%d %d\n", i+0+1, j+0+1 ) ;
						printf("%d %d\n", i-r+1, j+0+1 ) ;
						printf("%d %d\n", i+r+1, j+0+1 ) ;
						printf("%d %d\n", i+0+1, j-r+1 ) ;
						printf("%d %d\n", i+0+1, j+r+1 ) ;
						return 0 ;
					}
				}
			}
		}
	}
	
	printf("-1\n" ) ;
	
	return 0 ;
}

