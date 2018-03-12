#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005

int N ;
int arr[lim], usd[lim] ;

int main() {
	int maxP=0, res=0, W=0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	for( int i=0, j=0; i<N; i+=j ) {
		if( arr[i]>=0 ) {
			j = 1 ;
			continue ;
		}
		for( j=1; i+j<N && arr[i+j]<0; j++ ) ;
		maxP = max( maxP, j ) ;
		j *= 2 ;
		
		for( int k=1; k<=j && i-k>=0; k++ ) {
			if( !usd[i-k] ) {
				res ++ ;
				usd[i-k] = 1 ;
			}
		}
		
		j /= 2 ;q
	}
	
	for( int i=0, j=0; i<N; i+=j ) {
		if( arr[i]>=0 ) {
			j = 1 ;
			continue ;
		}
		for( j=1; i+j<N && arr[i+j]<0; j++ ) ;
		
		if( j!=maxP )
			continue ;
		
		int tmp = 0 ;
		j *= 3 ;
		for( int k=1; k<=j && i-k>=0; k++ ) {
			if( !usd[i-k] ) {
				tmp ++ ;
			}
		}
		
		W = max( W, tmp ) ;
		j /= 3 ;
	}
	
	printf("%d\n", res+W ) ;
	
	return 0 ;
}

