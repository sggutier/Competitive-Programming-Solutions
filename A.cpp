#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
#include <set>
#include <map>
using namespace std ;

long long mcd( long long A, long long B ) {
	long long C ;
	
	while( B ) {
		C = A%B ;
		A = B ;
		B = C ;
	}
	
	return A ;
}

int main() {
	long long N ;
	long long A=1LL, B=1LL, C=1LL, X;
	
	cin >> N ;
	
	if( N%6==0LL ) {
		X = (N-1LL)*(N-2LL)*(N-3LL) ;
	}
	else {
		A = N ;
		N -- ;
		while( N>1LL ) {
			if( mcd(A,N)==1LL ) {
				B = N ;
				break ;
			}
			N -- ;
		}
		N -- ;
		while( N>1LL ) {
			if( mcd(A,N)==1LL && mcd(B,N)==1LL ) {
				C = N ;
				break ;
			}
			N -- ;
		}
		X = A*B*C ;
	}
	
	cout << X << endl ;
	
	
	return 0 ;
}
