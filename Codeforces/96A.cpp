#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std ;

int main() {
	string S ;
	int N ;
	int carg = 0, res = 0 ;
	
	cin  >> S ;
	
	N = S.size() ;
	for( int i=0; i<N; i++ ) {
		if( i && S[i] == S[i-1]  )
			carg ++ ;
		else
			carg = 1 ;
		res = max( res, carg ) ;
	}
	
	if( res>=7 )
		printf("YES\n" ) ;
	else
		cout << "NO" << endl ;
	
	
	return 0 ;
}
