#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define pto pair <long double, long double>
#define x first
#define y second
#define mkp make_pair
const int inf = 1e9 ;
const double eps = 1e-9 ;
const int lim = 1e5 + 5 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;
#define lin pair< pto, pto >

long double calc_len( pto A, pto B ) {
    long double a=A.x-B.x, b=A.y-B.y ;
    return sqrt(a*a + b*b) ;
}

long double area_trian( pto A, pto B, pto C ) {
    pto arr[3] = { A, B, C } ;
    long double res = 1.0*0 ;
    for( int i=0; i<3; i++ ) {
	res += arr[i].x * arr[(i+1)%3].y ;
	res -= arr[i].y * arr[(i+1)%3].x ;
    }
    return fabs(res)/2.0 ;
}

long double calc_len( pto I, pto A, pto B ) {
    long double base = calc_len( A, B ) ;
    long double area = area_trian( I, A, B ) ;
    return area*2.0/base ;
}

long double incentro( pto A, pto B, pto C ) {
    long double c=calc_len( A, B ), a=calc_len( B, C ), b=calc_len( C, A ) ;

    // printf("%llf %llf %llf\n", a, b, c ) ;
    
    pto I = mkp( (a*A.x + b*B.x + c*C.x)/(a+b+c),
		 (a*A.y + b*B.y + c*C.y)/(a+b+c) ) ;
    //printf("--> %llf %llf\n", I.x, I.y ) ;

    long double p = calc_len( I, A, B ),
	q = calc_len( I, A, C ) ,
	r = calc_len( I, C, B ) ;

    //cout << p << " " << q << " " <<  r << endl ;

    return min( min(p,q), r ) ;    
}

long double dibuja( long double x, long double y, long double z ) {
    if( fabs(x)<eps or fabs(y)<eps or fabs(z)<eps )
	return 1.0*0 ;
    
    pto A, B, C ;
    long double ang ;
    A = mkp( 1.0*0, 1.0*0 ) ;
    B = A ;
    C = A ;
    B.x = x ;

    ang = acos( (z*z - x*x - y*y)/(-2.0*x*y) );
    C = mkp( y*cos(ang), y*sin(ang) ) ;

    // printf("%llf %llf ", A.x, A.y ) ;
    // printf("%llf %llf ", B.x, B.y ) ;
    // printf("%llf %llf\n", C.x, C.y ) ;
    // printf("%llf %llf %llf\n", calc_len(A,B), calc_len(B,C), calc_len(C,A) ) ;

    return incentro( A, B, C ) ;
}

int main() {
    long double x, y, z ;

    while( scanf("%llf%llf%llf", &x, &y, &z )!=EOF ) {
	printf("The radius of the round table is: %.3llf\n", dibuja(x,y,z) ) ;
    }
    
    return 0 ;
}
