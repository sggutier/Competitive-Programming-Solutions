#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std ;

int main() {
	string S ;
	int N ;
	string res ;
	int i ;
	
	cin >> S ;
	N = S.size() ;
	
	for( i=0; S[i]!='.'; i++ ) ;
	res = S.substr( 0, i ) ;
	
	if( S[i-1] == '9' ) {
		cout << "GOTO Vasilisa." << endl ;
		return 0 ;
	}
	if( S[i+1] >= '5' )
		res[i-1] ++ ;
	
	cout << res << endl ;
	
	return 0 ;
}
