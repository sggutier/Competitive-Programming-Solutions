#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
	int N, M, S ;
	int res = 0 ;
	int arr[300][300] ;

	scanf("%d%d%d", &N, &M, &S ) ;
	for( int i=1; i<=N; i++ ) {
		arr[i][0] = 0 ;
		for( int j=1; j<=M; j++ ) {
			scanf("%d", &arr[i][j] ) ;
			arr[i][j] += arr[i][j-1] ;
		}
	}

	for( int lo=1; lo<=M; lo++ ) {
		for( int ro=lo; ro<=M; ro++ ) {
			for( int ini=1, fin=1, carg=0; fin<=N; fin++ ) {
				carg += arr[fin][ro] - arr[fin][lo-1] ;
				while( ini<fin && carg>S ) {
					carg -= arr[ini][ro] - arr[ini][lo-1] ;
					ini ++ ;
				}
				if( carg==S )
					res ++ ;
			}
		}
	}

	printf("%d\n", res ) ;

	return 0 ;
}
