#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1005

int N ;
int res[lim][lim] ;
int arr[lim] ;

int main() {
	scanf("%d", &N );
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	for( int i=N-1, carg; i>=0; i-- ) {
		res[i][i] = arr[i] ;
		carg = arr[i] ;
		for( int j=i+1; j<N; j++ ) {
			carg += arr[j] ;
			res[i][j] = carg - min( res[i][j-1], res[i+1][j] ) ;
		}
	}
	
	printf("%d\n", res[0][N-1] ) ;
	
	return 0 ;
}
