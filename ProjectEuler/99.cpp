#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;

int main() {
	freopen( "base_exp.txt", "r", stdin ) ;
	
	int N, posRes ;
	double a, b ;
	double res = 1.0*0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%lf%lf", &a, &b ) ;
		if( log(a)*b >res ) {
			res = log(a)*b ;
			posRes = i ;
		}
	}
	
	printf("%d\n", posRes+1 ) ;
	
	return 0 ;
}
