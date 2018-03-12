#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int rep[500] ;
char S[500005] ;

int main() {
	int N, M, d ;
	char mapa[50][50] ;
	int W ;
	int i, j, r, c ;
	
	scanf("%d%d%d", &N, &M, &d ) ;
	d *= d ;
	for( i=0; i<N; i++ ) {
		scanf("%s", mapa[i] ) ;
	}
	scanf("%d", &W ) ;
	scanf("%s", S ) ;
	
	for( i=0; i<N; i++ ) {
		for( j=0; j<M; j++ ) {
			if( mapa[i][j] == 'S' ) 
				continue ;
			rep[ mapa[i][j] ] = 1 ;
			for( r=0; r<N; r++ ) {
				for( c=0; c<M; c++ ) {
					if( mapa[r][c] != 'S'  )
						continue ;
					if(  (r-i)*(r-i)  +  (c-j)*(c-j)   > d    ) {   
						if( !rep[ mapa[i][j] - 'a' + 'A' ]   ) 
							rep[ mapa[i][j] - 'a' + 'A' ] = 2 ; 
					}
					else {
						rep[ mapa[i][j] - 'a' + 'A' ] = 1 ;
					}
				}
			}
		}
	}
	
	d = 0 ;
	for( i=0; i<W; i++ ) {
		if( rep[S[i]] == 0 ) {
			cout << -1 << endl ;
			return 0 ;
		}
		d += rep[S[i]]-1 ;
	}
	
	cout << d << endl ;
	
	return 0 ;
}
