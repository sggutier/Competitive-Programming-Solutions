#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cmath>
using namespace std ;
const double PI = acos(-1.0);

struct pto {
    double x, y, z ;
    pto() {
    }
    pto( double _x, double _y, double _z ) {
        x = _x ;
        y = _y ;
        z = _z ;
    }
};

double dis( double x, double y ) {
    return sqrt(x*x + y*y) ;
}

bool operator<( pto A, pto B ) {
    return A.z < B.z ;
}

double ango(double x) {
    return x/(2*PI)*360.0;
}

int main() {
    int N ;
    pto arr[100005] ;
    double res = 1e9 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%lf%lf", &arr[i].x, &arr[i].y ) ;
        arr[i].z = acos( arr[i].x/dis(arr[i].x,arr[i].y) ) ;
        if( arr[i].y<0 )
            arr[i].z = 2*PI - arr[i].z ;
    }

    sort( arr, arr+N ) ;
    bool allig = true;
    for( int i=0; i<N; i++ ) {
        res = min(res, 2*PI - fmod(2*PI + arr[(i+1)%N].z - arr[i].z, 2*PI));
        if(fabs(arr[i].z-arr[0].z) > 1e-9)
            allig = false;
    }
    if(allig)
        res = 0.0;

    printf("%.9lf\n", ango(res));

    return 0 ;
}
