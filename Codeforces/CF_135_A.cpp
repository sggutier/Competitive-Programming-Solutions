#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	int arr[200000] ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
		
	sort( arr, arr+N ) ;
	if( arr[N-1]==1 ) 	arr[N-1] = 2 ;
	else 				arr[N-1] = 1 ;
	for( int i=N-1; i>0 && arr[i]<arr[i-1]; i-- )  swap( arr[i], arr[i-1] );
	
	for( int i=0; i<N; i++ )
		printf("%d ", arr[i] ) ;
	printf("\n" ) ;
	
	return 0 ;
}
