#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	int arr[10000] ;
	int sum = 0 ,  res=0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		sum += arr[i] ;
	}
	
	
	for( int i=0; i<N; i++ ) {
		if( (sum-arr[i])%2 == 0   )
			res ++ ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
