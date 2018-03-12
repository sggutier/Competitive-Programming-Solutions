#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	long long K ;
	int arr[100005] ;
	int a, b, r=0 ;
	
	cin >> N >> K ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
		
	sort( arr, arr+N ) ;
	K -- ;
	a = K/N ;
	for( int i=0; i<N; i++ ) 
		if( arr[i]==arr[a] )
			r ++ ;
			
	for( long long i=0LL; i<N; i++ ) {
		if( arr[i]==arr[a] ) {
			K -= N*i ;
			break ;
		}
	}
	
	b = K/r ;
	
	printf("%d %d\n", arr[a], arr[b] ) ;
	
	return 0 ;
}
