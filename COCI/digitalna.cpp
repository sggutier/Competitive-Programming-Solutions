#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	int N ;
	string S[200] ;
	int i ;
	
	cin >> N ;
	for( int i=0; i<N; i++ )
		cin >> S[i] ;
		
	for( i=0; S[i]!="BLJTV1"; i++ ) 
		printf("1" ) ;
	for( ; i; i-- ) {
		printf("4" ) ;
		swap( S[i], S[i-1] ) ;
	}
	for( i=0; S[i]!="BLJTV2"; i++ ) 
		printf("1" ) ;
	for( ; i>1; i-- ) {
		printf("4" ) ;
		swap( S[i], S[i-1] ) ;
	}
	printf("\n" ) ;
	
	return 0 ;
}
