#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;

int prueba( long long N ) {
	string S, K, x, y ;
	char tmp[1000] ;
	int res = 0 ;

	for( long long i=1LL; i*i<=N; i++ ) {
		sprintf( tmp, "%lld", i ) ;
		x = y = tmp ;
		sprintf( tmp, "%lld", i*i ) ;
		S =K = tmp ;
		reverse( K.begin(), K.end() ) ;
		reverse( y.begin(), y.end() ) ;
		if( S==K && x==y )
			res ++ ;
	}

	return res ;
}

void caso() {
	long long A, B ;

	cin >> A >> B ;

	cout << prueba( B ) - prueba(A-1) << endl ;
}

int main() {
	int T ;

	cin >> T ;
	for( int i=1; i<=T; i++ ) {
		cout << "Case #" << i << ": " ;
		caso() ;
	}

	return 0 ;
}


