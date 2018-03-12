#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
using namespace std ;
#define par pair<int,int>
#define x first
#define y second

int area( par a, par b, par c ) {
    return abs(   a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x  );
}

int main() {
    freopen( "triangles.txt", "r", stdin ) ;

    int N ;
    par a, b, c, cent=par(0,0) ;
    int res = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d%d", &a.x, &a.y ) ;
        scanf("%d%d", &b.x, &b.y ) ;
        scanf("%d%d", &c.x, &c.y ) ;
        if( area(a,b,c) == area(a,b,cent) + area(a,cent,c) + area(cent,b,c)  )
            res ++ ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
