#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int N=4 ;
	int arr[4] ;
	int res = 0 ;
	
	for( int i=0; i<N; i++ )
		cin >> arr[i] ;
		
	for( int i=0; i<N; i++ ) {
		int w = 0 ;
		for( int j=0; j<i; j++ )
			if( arr[i]!=arr[j] )
				w ++ ;
		if( w==i )
			res ++ ;
	}
	
	cout << 4-res << endl ;
	
	return 0 ;
}
