#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	int N ;
	string A ;
	
	scanf("%d", &N ) ;
	while( N ) {
		cin >> A ;
		
		N = A.size()/N ;
		for( int i=N; i<=A.size(); i+=N )  
			reverse( A.begin()+i-N, A.begin()+i ) ;
		cout << A << endl ;
		
		scanf("%d", &N ) ;
	}
}
