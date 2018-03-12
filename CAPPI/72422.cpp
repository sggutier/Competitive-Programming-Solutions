#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int N, M ;

int res( int r, int h, int lev, int vol ) {
    if( lev==0 ) {
        if( vol==0 )
            return r*r ;
        return (1<<30) ;
    }
    if( vol<=0 )
        return (1<<30) ;

    int a=(1<<30), x, w ;
    if( lev==1 ) {
        for( r++, h++;  (vol/(r*r))>=h;  r++  ) {
            if( vol%(r*r)==0  ) {
                a = min( a, r*r +  2*(vol/r) ) ;
            }
        }
        return a ;
    }
    for( r++, h++;  (vol/(r*r*lev))>=h;  r++  ) {
        w = r*r ;
        for( x=h; x*w*lev<=vol; x++ ) {
            a = min( a,  res( r, x, lev-1, vol-w*x  ) +  2*r*x  ) ;
        }
    }

    if( a!=(1<<30) )
        return a ;

    return (1<<30) ;
}

int main() {
    int W ;

    scanf("%d%d", &N, &M );

    W = max( 0, res( 0, 0, M, N )  );

    for( int r=1; r<=20; r++ ) {
        if( N%(r*r)==0  ) {
            int x = N/(r*r) ;
            int w = r*r ;
            //cout << r << " " << x << " " << 2*r*x + w << endl ;
        }
    }
    cout << W%(1<<30) << endl ;

    return 0 ;
}
