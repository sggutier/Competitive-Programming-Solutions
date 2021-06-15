#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	string S ;
	char W[] = "aeiouy" ;	
	string res ;
	
	cin >> S ;
	
	for( int i=0; i<S.size(); i++ ) {
		int j ;
		if( S[i] >= 'A' && S[i]<='Z'  )
			S[i] = S[i]-'A' + 'a' ;
		for( j=0; j<6 && S[i]!=W[j]; j++ ) ;
		if( j==6 ) {
			res += '.' ;
			res += S[i] ;
		}
	}
	
	cout << res << endl ;
	
	return 0 ;
}
