#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	double res = (1<<30)*1.0, a, b ;
	
	scanf("%lf%lf", &a, &b ) ;
	res = min( res, a/b ) ;
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%lf%lf", &a, &b ) ;
		res = min( res, a/b ) ;
	}
	
	printf("%.2lf\n", res*1000.00 ) ;
	
	return 0 ;
}
