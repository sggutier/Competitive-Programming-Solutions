#include <cstdio>
#include <iostream>
#include <algorithm>
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
    int N, a, b, c ;

    scanf("%d%d", &N, &a ) ;

    for( int i=1; i<N; i++ ) {
        scanf("%d", &b ) ;
        c = mcd(a,b) ;
        printf("%d/%d\n", a/c, b/c ) ;
    }

    return 0 ;
}
