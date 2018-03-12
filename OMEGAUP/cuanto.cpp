#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 100005 ;

long long carg[lim] ;

bool sePuede( int W , int A ) {
	long long res = 0LL ;
	
	for( int i=0; i<lim; i++ )
		res += (i/W)*carg[i] ;

	return res>=A ;	
}

int main() {
	int N, A ;
	int ini, fin, piv ;

	scanf("%d%d", &N, &A ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		carg[tmp] ++ ;
	}

	ini = 0 ; 
	fin = lim-1 ;
	while( ini<fin ) {
		piv = (ini+fin)/2 + (ini+fin)%2 ;
		if( sePuede(piv,A)  )
			ini = piv ;
		else
			fin = piv-1 ;
	}

	cout << ini << endl ;
	
	return 0 ; 
} 
