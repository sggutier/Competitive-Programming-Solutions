#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	string S ;
	int carg = 0 ;
	
	cin >> S ;
	
	for( int i=0; i<S.size(); i++ ) {		
		if( S[i+1] >= 'a' && S[i+1] <= 'z' ) {
			for( int j=0; j<carg; j++ )
				printf("  " ) ;
			carg ++ ;
		}
		else {
			carg -- ;
			for( int j=0; j<carg; j++ )
				printf("  " ) ;
		}
		for( ; S[i]!='>'; i++ )
			printf("%c", S[i] ) ;
		printf("%c\n", S[i] ) ;
	}
	
	return 0 ;
}

