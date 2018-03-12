#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std ;

double dis( double x1, double y1, double x2, double y2 ) {
	double a=x1-x2, b=y1-y2 ;
	return sqrt( a*a + b*b ) ;
}

int main() {
	double x1, x2, y1, y2, r1, r2 ;

	cin >> x1 >> y1 >> r1 ;
	cin >> x2 >> y2 >> r2 ;

	if( r2<r1 ) {
		swap( x1, x2 ) ;
		swap( y1, y2 ) ;
		swap( r1, r2 ) ;
	}

	if( dis(x1,y1,x2,y2) + r1 <= r2  ) 
		printf("%0.9lf\n", (r2 - (dis(x1,y1,x2,y2) + r1 ) ) / 2.0  ) ; 
	else
		printf("%0.9lf\n",  max(dis(x1,y1,x2,y2)-r1-r2, 0*1.0) / 2.0  ) ; 

	return 0 ;
}
