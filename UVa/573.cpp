#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int H ;
    double u, d, m ;

    while( scanf("%d%lf%lf%lf", &H, &u, &d, &m ) != EOF && H ) {
	int k = 0 ;
	m /= 100.0 ;
	m = u*m ;
	double pos = 1.0*0 ;
	do {
	    k ++ ;
	    pos += u ;
	    if( pos>H )
		break ;
	    pos -= d ;
	    u = max( 1.0*0, u - m ) ;
	    //cout << pos << " " << u << endl ;
	}while( pos>=0 && pos<=H ) ;
	printf("%s on day %d\n", pos>=H? "success":"failure", k ) ;
    }
    
    return 0 ;
}
