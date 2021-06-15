#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	long long res = 0LL ;
	int X, Y, N ;
	int r, c, a, b ;
	
	scanf("%d%d", &X, &Y ) ;
	scanf("%d%d", &r, &c ) ;
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int w = (1<<30) ;
		scanf("%d%d", &a, &b ) ;
		if( a<0 )
			w = min( w, -(r-1)/a ) ;
		else if( a>0 )
			w = min( w, (X-r)/a ) ;
		if( b<0 )
			w = min( w, -(c-1)/b ) ;
		else if( b>0 )
			w = min( w, (Y-c)/b ) ;
		res += w ;
		r += w*a ;
		c += w*b ;
	}
	
	cout << res << endl ;
	
}
