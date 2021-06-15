#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std ;

bool pand( vector <char> &A ) {
	int N = A.size() ;
	int rep[10] = {0,0,0,0,0,0,0,0,0,0} ;
	
	for( int i=0; i<N && i<9; i++ ) {
		rep[ A[i] ] |= 2 ;
		rep[ A[N-i-1] ] |= 1 ;
	}
	
	for( int i=1; i<10; i++ ) 
		if( rep[i]!=3 )
			return 0 ;
			
	return 1 ;
}

void  suma( vector <char> &A, vector <char> &B ) {
	if( A.size() > B.size() )
		B.push_back(0) ;
	int carg=0 ;
	
	for( int i=0; i<A.size(); i++  ) {
		A[i] += B[i] +carg ;
		carg = A[i]/10 ;
		A[i] %= 10 ;
	}
	
	if( carg )
		A.push_back(carg) ;
		
	return ;
}

int main() {
	vector <char> A, B, C ;
	
	A.push_back(1LL) ;
	B = A ;
	
	
	
	for( int i=2; i<100000000; i++ ) {
		if( pand(B) ) {
			printf("%d\n", i ) ;
			return 0 ;
		}
		C = B ;
		suma( B, A ) ;
		A = C ;
		
		/*for( int j=A.size()-1; j>=0; j-- )
			printf("%d", A[j] ) ;
		printf(" " ) ;
		for( int j=B.size()-1; j>=0; j-- )
			printf("%d", B[j] ) ;*/
		printf(" %d\n", i ) ;
		//getchar() ;
	}
	
	return 0 ;
}
