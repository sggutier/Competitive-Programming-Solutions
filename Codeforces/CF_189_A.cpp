#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int N, a, b, c ;
    int res = 0 ;

    scanf("%d%d%d%d", &N, &a, &b, &c ) ;

    for( int i=0; i<=4000; i++ ) {
        for( int j=0; j<=4000; j++ ) {
            if( N<i*a + j*b  ||  (N-(i*a + j*b))%c  )
                continue ;
            res = max( res, i + j + (N-(i*a + j*b))/c) ;

        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
