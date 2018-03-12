#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int N, M ;
	int arr[200] ;
	int res = 0 ;
	
	cin >> N >> M ;
	for( int i=0; i<N; i++ )
		cin >> arr[i] ;
		
	for( int i=0; i<N; i++ ) 
		for( int j=i+1; j<N; j++ ) 
			for( int k=j+1; k<N; k++ ) 
				if( arr[i]+arr[j]+arr[k] <= M )
					res = max( res, arr[i]+arr[j]+arr[k] ) ;
	
	cout << res << endl ;
	
	return 0 ;
}
