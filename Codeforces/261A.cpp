#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std ;

int main() {
	int N, M, K ;
	int arr[10000] ;
	int res = 0 ;

	cin >> N >> M >> K ;
	for( int i=0; i<N; i++ ) {
		cin >> arr[i] ;
	}

	sort( arr, arr+N ) ;
	reverse( arr, arr+N ) ;
	for( int i=0; i<N && M>K; i++ ) {
		if( K-1+arr[i]<=K )
			break ;
		K += arr[i]-1 ;
		res ++ ;
	}

	if( M>K )
		res = -1 ;
	cout << res << endl ;

	return 0 ;
}
