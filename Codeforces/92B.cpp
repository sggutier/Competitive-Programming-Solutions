#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std ;

int main() {
	string A ;
	int i, j, N ;
	int res = 0 ;
	
	cin >> A ;
	
	N = A.size() ;
	
	reverse( A.begin(), A.end()  )  ;
	A += "0" ;
	for( i=0; A[i]=='0'; i++, res++ ) ;
	while( i<N-1 ) {
		res ++ ;
		for( ; A[i]=='1'; i++, res++ )  ;
		A[i] = '1' ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
