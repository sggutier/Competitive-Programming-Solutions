#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int N;
int rep[300] ;
int qua[300] ;

int main() {
	string A, B, C ;
	
	cin >> A ;
	for( int i=0; i<A.size() ; i++ ) 
		rep[A[i]] ++ ;
	cin >> A ;
	for( int i=0; i<A.size() ; i++ ) 
		rep[A[i]] ++ ;
	cin >> A ;
	for( int i=0; i<A.size() ; i++ ) 
		qua[A[i]] ++ ;
		
	for( int i=0; i<300; i++ ) {
		if( qua[i]!=rep[i] ) {
			printf("NO\n" ) ;
			return 0 ;
		}
	}
	
	printf("YES\n" ) ;
	
	return 0 ;
}
