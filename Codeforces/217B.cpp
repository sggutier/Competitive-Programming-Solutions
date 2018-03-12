#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int usd[100][100] ;

int main() {
	int N = 0 ;
	int w = 0 ;

	cin >> N ;

	for( int i=0; i<(1<<N); i++ ) {
		int a=0, b=1 ;
		for( int j=0; j<N; j++ ) {
			if( (1<<j) & i )
				a += b ;
			else
				b += a ;
		}
		//printf("%d %d\n", a, b ) ;
		if( usd[a][b] ) {
			//cout << "nov" << endl ;
			w ++ ;
		}
		usd[a][b] = 1 ;
		usd[b][a] = 1 ;
		//getchar() ;

	}
	cout << w << endl ;

	return 0 ;
}
