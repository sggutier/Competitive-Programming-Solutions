#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
    int a, b, c ;
    int res = 0 ;

    scanf("%d%d%d", &a, &b, &c ) ;

    if( c<b )
        swap( c, b ) ;
    if( b<a )
        swap( a, b ) ;
    while( a && b && c ) {

        if( a>1 )
            res += (a+b+c-3)*2 ;
        else
            res += c*b ;
        a -- ;
        b -- ;
        c -- ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
