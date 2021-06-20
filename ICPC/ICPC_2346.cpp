#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const double eps = 0.00000001 ;

void caso( double r1, double r3, double H, double h ) {
	double x, w, t, r2 ;

	x = (r3-r1)/H ;
	r2 = r1 + h*x ;
	w = r2/x ;
	t = r3/x ;

	if( r1+eps < r3 )
		printf("%.4lf\n", M_PI*( r3*r3*t - r2*r2*w )/3.0 ) ;
	else
		printf("%.4lf\n", M_PI*(r3*r3)*(H-h) ) ;
}

int main() {
	int a, b, c, d ;

	scanf("%d%d%d%d", &a, &b, &c, &d ) ;
	while( a ) {
		caso( a*1.0, b*1.0, c*1.0, d*1.0 ) ;
		scanf("%d%d%d%d", &a, &b, &c, &d ) ;
	}

	return 0 ;
}


