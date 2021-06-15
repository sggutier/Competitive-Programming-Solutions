#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int adj[5][5] ;

int main() {
	int E ;
	int i, a, b ;
	
	scanf("%d", &E ) ;
	while( E ) {
		E -- ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		adj[a][b] = 1 ;
		adj[b][a] = 1 ;
	}
	
	for( i=0; i<5; i++ ) {
		for( a=i+1; a<5; a++ ) {
			for( b=a+1; b<5; b++ ) {
				if( adj[i][a] && adj[i][b] && adj[a][b] ) {
					printf("WIN\n" ) ;
					return 0 ;
				}
				if( !adj[i][a] && !adj[i][b] && !adj[a][b] ) {
					printf("WIN\n" ) ;
					return 0 ;
				}
			}
		}
	}
	
	printf("FAIL\n" ) ;
	
	return 0 ;
}
