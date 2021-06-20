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

void caso() {
	int N ;
	string A, B ;
	int a=-(1<<30), b=a ;
	char tmp[1000] ;

	scanf("%d", &N ) ;
	scanf("%s", tmp ) ;
	A = tmp ;
	for( int i=0, w=0, crg=0; i<N; i++ ) {
		int k ;
		scanf("%d", &k ) ;
		crg += k ;
		a = max( a, crg-w ) ;
		w = min( w, crg ) ;
	}
	scanf("%s", tmp ) ;
	B = tmp ;
	for( int i=0, w=0, crg=0; i<N; i++ ) {
		int k ;
		scanf("%d", &k ) ;
		crg += k ;
		b = max( b, crg-w ) ;
		w = min( w, crg ) ;
	}

	if( a==b ) 
		cout << "Tied " << a << endl ;
	else
		cout << ( (a>b)? A : B ) << " " << max(a,b) << endl ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) 
		caso() ;

	return 0 ;
}


