#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	string S ;
	int N, W = 0 ;
	
	cin >> S ;
	N = S.size() ;
	
	for( int i=1; i<N; i++ ) {
		if( S[i]>='A' && S[i]<='Z' ) 
			W ++ ;
	}
	
	if( W==N-1 ) {
		for( int i=0; i<N; i++ ) {
			if( S[i]>='A' && S[i]<='Z' ) 
				S[i] = S[i]-'A' + 'a' ;
			else if( S[i]>='a' && S[i]<='z' ) 
				S[i] = S[i]+'A' - 'a' ;
		}
	}
	
	cout << S << endl ;
	
	
	return 0 ;
}


