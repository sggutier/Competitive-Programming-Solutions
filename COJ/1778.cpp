#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N ;
	double a, b ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%lf%lf", &a, &b ) ;
		printf("%0.8lf\n", a*b*3.0/16.0 ) ;
	}
	
	return 0 ;
}
