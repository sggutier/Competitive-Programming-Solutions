#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int N, M ;
	int arr[100], arr2[100] ;
	int res = 0, nRes=0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
	scanf("%d", &M ) ;
	for( int i=0; i<M; i++ ) 
		scanf("%d", &arr2[i] ) ;
		
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<M; j++ ) {
			if( arr2[j]%arr[i] )
				continue ;
			if( arr2[j]/arr[i]>res ) {
				res = arr2[j]/arr[i] ;
				nRes = 1 ;
			}
			else if( arr2[j]/arr[i]==res ) {
				nRes ++ ;
			}
		}
	}
	
	printf("%d\n", nRes ) ;
	
	return 0 ;
}
