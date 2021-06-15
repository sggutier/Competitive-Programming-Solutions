#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std ;

int rep[300] ;

int main() {
	int K, N ;
	string S, res ;

	cin >> K >> S ;
	N = S.size() ;

	for( int i=0; i<N; i++ )
		rep[S[i]] ++ ;

	for( int i=0; i<300; i++ ) {
		if( rep[i]%K ) {
			printf("-1\n" ) ;
			return 0 ;
		}
		for( int j=0; j<rep[i]/K; j++ ) 
			res += char(i) ;
	}

	for( int i=0; i<K; i++ )
		cout << res ;
	cout << endl ;

	return 0 ;
}
