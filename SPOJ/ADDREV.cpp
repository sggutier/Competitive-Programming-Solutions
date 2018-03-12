#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std ;

void caso() {
	string A, B ;
	int N ;
	
	cin >> A >> B ;
	
	
	while( B.size()<A.size()   ) 
		B += "0" ;
	while( A.size()<B.size()   ) 
		A += "0" ;
		
	for( int i=0; i<A.size(); i++ ) 
		A[i] -= '0' ;
	for( int i=0; i<B.size(); i++ ) 
		B[i] -= '0' ;
	
	
		
	N = A.size() ;
	for( int i=0; i<N; i++ ) {
		A[i] += B[i] ;
		if( A[i]>=10 ) {
			if( i+1>=N ) {
				A += '0' ;
				A[i+1] -= '0' ;
			}
			A[i+1] += A[i]/10 ;
			A[i] %= 10 ;
		}
	}
	
	for( int i=0; i<A.size(); i++ ) {
		A[i] += '0' ;
	}
	for( int i=0; i<A.size(); i++ ) {
		if( A[i]!='0' ) {
			A = A.substr( i, A.size()-i  );
			break ;
		}
	}
	
	cout << A << endl ;
}

int main() {
	int T ;
	
	scanf("%d", &T ) ;
	
	for( int i=0; i<T; i++ ) {
		caso() ;
	}
	
	return 0 ;
}
