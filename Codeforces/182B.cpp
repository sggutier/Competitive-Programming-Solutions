#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int D, N, res=0 ;
	int arr[10000] ;
	
	scanf("%d%d", &D, &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	for( int i=0; i+1<N; i++ ) 
		res += D-arr[i] ;
	cout << res << endl ;
	
	return 0 ;
}
