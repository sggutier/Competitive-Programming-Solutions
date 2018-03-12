#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10000

int dis( int xa, int ya, int xb, int yb  ) {
	int A = xa-xb, B=ya-yb ;
	return A*A + B*B ;
}

int main() {
	int A, B, C, D ;
	int x, y ;
	int N ;
	int calen[lim][3] ;
	int res = 0 ;
	
	cin >> A >> B >> C >> D ;
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		cin >> calen[i][0] >> calen[i][1] >> calen[i][2] ;
		calen[i][2] *= calen[i][2] ;
	}
	
	if( A>C )
		swap( A, C ) ;
	if( B>D )
		swap( B, D ) ;
		
	for( x=A, y=B; x<C; x++ ) {
		int i=0;
		for( ; i<N; i++ ) {
			if( dis( calen[i][0], calen[i][1], x, y ) <= calen[i][2]  )
				break ;
		}
		if( i==N )
			res ++ ;
	}
	for( x=C, y=B; y<D; y++ ) {
		int i=0;
		for( ; i<N; i++ ) {
			if( dis( calen[i][0], calen[i][1], x, y ) <= calen[i][2]  )
				break ;
		}
		if( i==N )
			res ++ ;
	}
	for( x=C, y=D; x>A; x-- ) {
		int i=0;
		for( ; i<N; i++ ) {
			if( dis( calen[i][0], calen[i][1], x, y ) <= calen[i][2]  )
				break ;
		}
		if( i==N )
			res ++ ;
	}
	for( x=A, y=D; y>B; y-- ) {
		int i=0;
		for( ; i<N; i++ ) {
			if( dis( calen[i][0], calen[i][1], x, y ) <= calen[i][2]  )
				break ;
		}
		if( i==N )
			res ++ ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}


