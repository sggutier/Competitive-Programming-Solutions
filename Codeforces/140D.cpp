#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 103

int main() {
	int N ;
	int arr[lim], sum=10 ;
	int resP=0, resT=0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;

	sort( arr, arr+N ) ;
	for( int i=0; i<N; i++ ) {
		sum += arr[i] ;
		if( sum>60*12 )
			break ;
		resP ++ ;
		resT += max( 0, sum-60*6  ) ;
	}
	
	printf("%d %d\n", resP, resT ) ;
	
	return 0 ;
}
