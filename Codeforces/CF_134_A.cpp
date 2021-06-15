#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 300000

int main() {
	int N, R=0 ;
	int arr[lim], res[lim] ;
	int sum=0 ;
	
	scanf("%d", &N )  ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		sum += arr[i] ;
	}
	
	for( int i=0; i<N; i++ ) {
		sum -= arr[i] ;
		if( sum%(N-1)==0  &&  sum/(N-1)==arr[i]  )
			res[R++] = i ;
		sum += arr[i] ;
	}

	printf("%d\n", R ) ;
	for( int i=0; i<R; i++ )
		printf("%d ", res[i]+1 ) ;
	printf("\n" ) ;
	
	return 0 ;
}
