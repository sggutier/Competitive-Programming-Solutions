#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int N ;
long long rep[21] ;

int main() {
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a ;
		scanf("%d", &a ) ;
		rep[a+10] ++ ;
	}
	
	long long res = 0LL ;
	for( int i=0; i<10; i++ ) {
		res += rep[i]*rep[10 + (10-i) ] ;
	}
	res += (rep[10]*(rep[10]-1))/2 ;
	
	cout << res << endl ;

	return 0 ;
}
