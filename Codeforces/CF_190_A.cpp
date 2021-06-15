#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;

int main() {
	int A, B ;
	
	cin >> A >> B ;
	
	if( A==0 && B>0 ) {
		cout << "Impossible" << endl ;
		return 0 ;
	}
	
	printf("%d %d\n", A + max( 0, B-A ), A + max( 0, B-1 )  ) ;
	
	return 0 ;
}


