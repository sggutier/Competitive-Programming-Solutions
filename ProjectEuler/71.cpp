#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 1000006

struct frac {
    int x, y ;
    frac() {
    }
    frac( int a, int b ) {
        x = a ;
        y = b ;
    }
};

bool operator<( frac a, frac b ) {
    a.x *= b.y ;
    b.x *= a.y ;
    return a.x<b.x ;
}

frac res[lim] ;

int main() {
    int N ;
    double a=3.0, b=7.0 ;

    scanf("%d", &N ) ;

    for( int i=0; i<N; i++ ) {
        res[i] = frac(  ceil( (i+1)*a/b )-1, i+1 ) ;
    }

    sort( res, res+N ) ;

    printf("%d/%d\n", res[N-1].x, res[N-1].y ) ;

    return 0 ;
}
