#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	int arr[10000] ;
	int minH = 1222, maxH = -10000 ;
	int res = 0 ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		cin >> arr[i] ;
		minH = min( minH, arr[i] ) ;
		maxH = max( maxH, arr[i] ) ;
	}
		
	for( int i=0; i<N; i++ ) {
		if( arr[i] != maxH )
			continue ;
		for( ; i; i--, res++ )
			swap( arr[i], arr[i-1] ) ;
		break ;
	}
	for( int i=N-1; i>=0; i-- ) {
		if( arr[i] != minH )
			continue ;
		for( ; i+1<N; i++, res++ )
			swap( arr[i], arr[i+1] ) ;
		break ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}


