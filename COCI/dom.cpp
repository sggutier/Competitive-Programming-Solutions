#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	string A, B ;
	
	A = "CAMBRIDGE" ;
	cin >> B ;
	
	for( int i=0; i<B.size(); i++ ) {
		bool found = 0 ;
		for( int j=0; j<A.size(); j++ )
			if( A[j]==B[i] )
				found = 1 ;
		if( !found )
			cout << B[i] ;
	}
	cout << endl ;
	
	return 0 ;
}
