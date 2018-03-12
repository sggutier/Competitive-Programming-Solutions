#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;
#define lim 100005

int N, M ;
string S[lim] ;

int main() {
	int res = 0 ;
	
	cin >> N ;
	for( int i=0; i<N; i++ )
		cin >> S[i] ;	
	M = S[0].size() ;
	
	for( ; res<M; res++ ) {
		int i ;
		for( i=0; i<N && S[i][res]==S[0][res]; i++ ) ;
		if( i!=N )
			break ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
