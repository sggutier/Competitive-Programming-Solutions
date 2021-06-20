#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 100005 ;

struct coord {
    char tp ;
    double aX, aY, bX, bY ;

    coord() {
    }
    
    coord( char K )  {
	tp = K ;
	if( K=='r' )
	    scanf("%lf%lf%lf%lf", &aX, &bY, &bX, &aY ) ;
	else
	    scanf("%lf%lf%lf", &aX, &aY, &bX ) ;
    }

    bool dentro( double x, double y ) {
	if( tp=='r' )
	    return aX <= x and x <= bX and aY<=y and y<=bY   ;
	else {
	    double a=x-aX, b=y-aY ;
	    return a*a + b*b <= bX*bX ;
	}
    }
};

int N = 0 ;
coord figs[lim] ;

int main() {
    char S[5] ;
    double a, b ;
    int K = 0 ;
    double eps = 1.0e-6 ;

    while( scanf("%s", S)!=EOF and S[0]!='*' ) {
	figs[N++] = coord(S[0]) ;
    }

    while( scanf("%lf%lf", &a, &b )!=EOF and (fabs(a-9999.9)>=eps or fabs(b-9999.9)>=eps )  ) {
	K ++ ;
	bool fnd = 0 ;
	for( int i=0; i<N; i++ ) {
	    if( figs[i].dentro(a,b) ) {
		fnd = 1 ;
		printf("Point %d is contained in figure %d\n", K, i+1 ) ;
	    }
	}
	if( !fnd )
	    printf("Point %d is not contained in any figure\n", K ) ;
    }
    
    return 0 ;
}
