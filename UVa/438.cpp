-#include <cstdio>
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
using namespace std ;
const int lim = 100005 ;
#define pto pair < long double, long double >
#define x first
#define y second

const long double eps = 1e-9 ;

struct eq {
    long double A, B, C ;
    eq() {
    }
    eq( long double _A, long double _B, long double _C ) {
	A = _A ;
	B = _B ;
	C = _C ;
    }
    eq( pto X, pto Y ) {
	A = Y.y - X.y ;
	B = X.x - Y.x ;
	C = A * X.x  +  B* X.y ;
    }
};

bool ISec( eq X, eq Y, pto &res ) {
    long double det = X.A * Y.B - X.B * Y.A ;
    // cout << det << endl ;
    if( fabs(det) < eps )
	return false ;

    res.x = ( Y.B * X.C - X.B * Y.C ) / det ;
    res.y = ( X.A * Y.C - Y.A * X.C ) / det ;
    
    return true ;
}

long double dst( pto A, pto B ) {
    long double x = A.x - B.x ,  y = A.y - B.y ;
    return sqrt( x*x + y*y ) ;
}

pto mita( pto A, pto B ) {
    return pto( (A.x+B.x)/2.0, (A.y+B.y)/2.0 ) ;
}

int main() {
    pto p, q, r, O, a, b ;
    eq m, n, m2, n2 ;

    while( scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &p.x, &p.y, &q.x, &q.y, &r.x, &r.y ) != EOF  )  {
	m = eq( p, q ) ;
	n = eq( q, r ) ;

	a = mita( p, q ) ;
	b = mita( q, r ) ;

	m2 = eq( -m.B, m.A, ( -m.B*a.x + m.A*a.y )  ) ;
	n2 = eq( -n.B, n.A, ( -n.B*b.x + n.A*b.y )  ) ;

	/* printf( " ^^^^^^ %Lf %Lf\n", a.x, a.y ) ;
	printf( " ^^^^^^ %Lf %Lf\n", b.x, b.y ) ;

	cout << " <<<< " << m .A << " " << m .B << " " << m .C << endl ;
	cout << " <<<< " << n .A << " " << n .B << " " << n .C << endl ;
	
	cout << " >>>> " << m2.A << " " << m2.B << " " << m2.C << endl ;
	cout << " >>>> " << n2.A << " " << n2.B << " " << n2.C << endl ;*/
	if( ISec( m2, n2, O )  ) {
	    //cout << O.x << " " << O.y << endl ;
	    printf("%.2Lf\n", 2.0*M_PI*dst( O, p )  ) ;
	}
	else {
	    long double a = dst(p,q) ;
	    a = max( a, dst(q,r) ) ;
	    a = max( a, dst(p,r) ) ;
	    printf("%.2Lf\n", M_PI*a  ) ;
	}
    }
    
    return 0 ;
}
