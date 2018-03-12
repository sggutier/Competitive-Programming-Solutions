#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 500 ;

int N ;
int arr[lim][lim] ;

int main() {
	int sum = 0 ;
	int r, c ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<N; j++ )
			scanf("%d", &arr[i][j] ) ;

	r = 0, c=0 ;
	while( r<N ) {
		sum += arr[r][c] ;
		arr[r][c] = 0 ;
		r ++ ;
		c ++ ;
	}

	r = 0, c=N-1 ;
	while( r<N ) {
		sum += arr[r][c] ;
		arr[r][c] = 0 ;
		r ++ ;
		c -- ;
	}

	r = N/2, c=0 ;
	while( c<N ) {
		sum += arr[r][c] ;
		arr[r][c] = 0 ;
		c ++ ;
	}

	r = 0, c=N/2 ;
	while( r<N ) {
		sum += arr[r][c] ;
		arr[r][c] = 0 ;
		r ++ ;
	}

	printf("%d\n", sum ) ;

	return 0 ;
}
