#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int mcd( int a, int b ) {
    int c ;
    while( b ) {
        c = a%b ;
        a = b ;
        b = c ;
    }
    return a ;
}

int main() {
    int N ;
    int res = 0 ;

    scanf("%d", &N ) ;
    res = N*N ;

    for( int a=0; a<=N; a++ ) {
        for( int b=0; b<=N; b++ ) {
            if( a==0 && b==0 )
                continue ;
            int x, y ;
            x = mcd(a,b) ;
            y = -a/x ;
            x = b/x ;
            //printf("%d %d -> %d %d\n", a, b, x, y ) ;
            //getchar() ;
            for( int c=-1000; c<=1000; c++ ) {
                //if( a+c*x==0 && b+c*y==0 )
                //    continue ;
                if( c==0 )
                    continue ;
                if( a+c*x>=0 && a+c*x<=N && b+c*y>=0 && b+c*y<=N ) {
                    res ++ ;
                //printf("%d %d -> %d %d\n", a, b, a+c*x, b+c*y ) ;
                }
            }
        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
