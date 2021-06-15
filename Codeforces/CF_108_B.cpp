#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int N ;
	int arr[100000] ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	sort( arr, arr+N ) ;
	
	for( int i=1; i<N; i++ ) {
		if( arr[i]<arr[i-1]*2 && arr[i]!=arr[i-1]  )  {
			cout << "YES" << endl ;
			return 0 ;
		}
	}
	cout << "NO" << endl ;
	
	return 0 ;
}
