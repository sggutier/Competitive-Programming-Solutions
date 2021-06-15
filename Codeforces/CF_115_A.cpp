#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 2005

int main() {
	int N ;
	int padre[lim] ;
	int res = 0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &padre[i] ) ;
	
	for( int i=0; i<N; i++ ) {
		int tmp = 0 ;
		for( int pos=i; pos!=-2; pos=padre[pos]-1, tmp++  )  ;
		res = max( res, tmp ) ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
