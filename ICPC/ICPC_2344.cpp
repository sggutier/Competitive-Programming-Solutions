#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;

struct dat {
	string S ;
	int a, b, c ;
	dat() {
	}
	dat( string _S, int _a, int _b, int _c ) {
		S = _S ;
		a = _a ;
		b = _b ;
		c = _c ;
	}
};

bool operator<( dat A, dat B ) {
	if( A.a != B.a ) 
		return A.a > B.a ;
	if( A.b != B.b ) 
		return A.b > B.b ;
	if( A.c != B.c ) 
		return A.c > B.c ;
	return A.S < B.S ;
}

bool caso(int T) {
	int N ;
	dat arr[100] ;
	char tmp[1000] ;

	scanf("%s", tmp ) ;
	for( N=0; tmp[0]!='@' && tmp[0]!='#'; N++ ) {
		int a, b, c ;
		scanf("%d%d%d", &a, &b, &c ) ;
		arr[N] = dat( tmp, a, b, c ) ;
		scanf("%s", tmp ) ;
	}

	sort( arr, arr+N ) ;

	if( T ) 
		cout << "@\n" ;
	for( int i=0; i<N; i++ ) 
		cout << arr[i].S << endl ;

	return tmp[0]=='#' ;
}

int main() {
	for( int i=0; !caso(i); i++ ) {
	}

	return 0 ;
}


