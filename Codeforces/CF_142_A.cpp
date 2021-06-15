#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define inf (1LL<<60)

int main() {
	int N ;
	long long a, b, c, d, x ;
	long long minVol = inf, maxVol = -inf ;
	
	scanf("%d", &N ) ;
	
	for( a=1LL; a*a<=N; a++ ) {
		if( N%a )
			continue ;
		d = N/a ;
		for( b=1LL; b*b<=d; b++ ) {
			if( d%b )
				continue ;
			c = d/b ;
			x = (a+1)*(b+2)*(c+2)  -  a*b*c ;
			minVol = min( minVol, x ) ;
			maxVol = max( maxVol, x ) ;
		}
		if( b-1LL != d ) {
			b = d ;
			c = d/b ;
			x = (a+1)*(b+2)*(c+2)  -  a*b*c ;
			minVol = min( minVol, x ) ;
			maxVol = max( maxVol, x ) ;
		}
	}
	if( a-1LL != N ) {
		a = N ;
		d = N/a ;
		for( b=1LL; b*b<=d; b++ ) {
			if( d%b )
				continue ;
			c = d/b ;
			x = (a+1)*(b+2)*(c+2)  -  a*b*c ;
			minVol = min( minVol, x ) ;
			maxVol = max( maxVol, x ) ;
		}
		if( b-1LL != d ) {
			b = d ;
			c = d/b ;
			x = (a+1)*(b+2)*(c+2)  -  a*b*c ;
			minVol = min( minVol, x ) ;
			maxVol = max( maxVol, x ) ;
		}
	}
	
	cout << minVol << " " << maxVol << endl ;
	
	return 0 ;
}

