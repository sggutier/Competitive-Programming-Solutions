#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 300

int rep[lim] ;

int main() {
	int N, res=0 ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		int a ;
		scanf("%d", &a ) ;
		rep[a] ++ ;
	}
	
	for( int i=0; i<lim; i++ ) 
		res += rep[i] / 2 ;
	
	printf("%d\n", res/2 ) ;
	
	return 0 ;
}
