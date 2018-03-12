#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std; 
#define limK 205
#define limN 205

int N, K ;
int res[limN][limK] ;

int main() {
	int i, j ;
	int W ;
	
	scanf("%d%d", &N, &K  ) ;
	for( i=0; i<=N; i++ )	
		for( j=0; j<K; j++ ) 	
			res[i][j] = -1 ;
	res[0][0] = 0 ;
	for( i=0; i<N; i++ ) {
		scanf("%d", &W ) ;
		W %= K ;
		for( j=0; j<K; j++ )
			res[i+1][j] = res[i][j] ;
		for( j=0; j<K; j++ ) { 
			if( res[i][j] != -1 ) 
				res[i+1][(j+W)%K] = max( res[i+1][(j+W)%K], res[i][j] + 1  )  ;
		}
	}
	
	printf("%d\n", res[N][0] ) ;
	
	return 0 ;
}
