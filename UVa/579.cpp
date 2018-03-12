#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int A, B ;

    while( scanf("%d:%d", &A, &B ) && (A||B) ) {
	double a, b ;
	A %= 12 ;
	A *= 5 ;
	B %= 60 ;
	b = B*6.0 ;
	a = (A + B/12.0)*6.0 ;
	if( a<b )
	    swap( a,b ) ;
	double dst = a-b ;
	dst = min( dst, 360.0-dst ) ;
	printf("%.3lf\n", dst ) ;
    }
    
    
    return 0 ;
}
