#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1025

int bit[lim][lim] ;

void mete( int X, int Y, int nov ) {
    for( int i=X; i<lim; i+=(i & -i)  )
        for( int j=Y; j<lim; j+=(j & -j)  )
            bit[i][j] += nov ;
}

int carga( int X, int Y ) {
    int res = 0 ;
    for( int i=X; i>0; i-=(i & -i)  )
        for( int j=Y; j>0; j-=(j & -j)  )
            res += bit[i][j] ;
    return res ;
}

int main() {
    int A ;

    scanf("%d", &A ) ;
    scanf("%d", &A ) ;
    while( A!=3 ) {
        if( A==1 ) {
            int a, b, c ;
            scanf("%d%d%d", &a, &b, &c ) ;
            a++, b++ ;
            mete( a, b, c ) ;
        }
        else {
            int a, b, c, d ;
            scanf("%d%d%d%d", &a, &b, &c, &d ) ;
            c ++, d++ ;
            printf("%d\n", carga(c,d) - carga(a,d) - carga(c,b) + carga(a,b)   ) ;
        }

        scanf("%d", &A ) ;
    }

    return 0 ;
}
