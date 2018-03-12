#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std ;
const int N = 6 ;

string arr[N] ;

int main() {
	for( int i=0; i<6; i++ )
		cin >> arr[i] ;
		
	sort( arr, arr+N ) ;
	do {
		bool w = 1 ;
		for( int i=0; i<3; i++ ) {
			for( int j=0; j<3; j++ ) {
				if( arr[i][j]!=arr[j+3][i] )
					w = 0 ;
			}
		}
		if( w ) {
			for( int i=0; i<3; i++ )
				cout << arr[i] << endl ;
			return 0 ;
		}
	}while( next_permutation( arr, arr+N )   );
	
	cout << 0 << endl ;
	
	return 0 ;
}
