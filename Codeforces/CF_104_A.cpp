#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int n ;
	int res[1000] ;
	
	cin >> n ;
	res[0] = 0 ;
	for( int i=1; i<12; i++ )
		res[i] = 4 ;
	res[10] = 15 ;
	
	cout << res[max(0,n-10)] << endl ;
	
	return 0 ;
}
