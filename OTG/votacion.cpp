#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std ;
#define limV 10005
#define limC 55

int main() {
	int V, C ;
	int opc[limV][limC] ;
	int rep[limC], elim[limC] ;
	int cD ;
	int i, j, maxV, minV ;
	
	scanf("%d%d", &C, &V ) ;
	for( i=0; i<V; i++ ){
		for( j=0; j<C; j++ ) {
			scanf("%d", &opc[i][j] ) ;
		}
	}
	
	cD = C ;
	memset( elim, 0, sizeof(elim)  ) ;
	while( cD )  {
		maxV = 0 ;
		minV = (1<<30) ;
		memset( rep, 0, sizeof(rep)  ) ;
		for( i=0; i<V; i++ ) {
			for( j=0; elim[opc[i][j]]; j++ ) ;
			rep[ opc[i][j] ] ++ ;
		}
		for( i=1; i<=C; i++ )  {
			if( !elim[i] ) {
				maxV = max( maxV, rep[i] ) ;
				minV = min( minV, rep[i] ) ;
			}
		}
		if( maxV*2 <= C ) {
			for( i=1; i<=C; i++ ) {
				if( rep[i] == minV )  {
					elim[i] = 1 ;
					cD -- ;
				}
			}
		}
		else {
			break ;
		}
	} 
	
	if( cD ) {
		for( i=1; rep[i] != maxV; i++ ) ;
	}
	else {
		i = 0 ;
	}
	printf("%d\n", i ) ;
	
	return 0 ;
}
