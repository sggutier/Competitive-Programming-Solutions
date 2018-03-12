#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 100005
#define ado 500000

long long res[lim], eg[10*lim] ;

void prec() {
    int N = 100000 ;
    int a, carg=0 ;

    for( int i=1; i<=N; i++ ) {
        res[i] += res[i-1] ;
        a = i ;
        while( a ) {
            if( a%10==4 )
                carg ++ ;
            else if( a%10==7 )
                carg -- ;
            a /= 10 ;
        }
        if( carg==0 )
            res[i] ++ ;
        res[i] += eg[ado+carg] ;
        eg[carg+ado] ++ ;
    }
}

int main() {
    prec() ;
    int T, N ;

    for( scanf("%d", &T); T; T-- ) {
        scanf("%d", &N ) ;
        printf("%lld\n", res[N] ) ;
    }

    return 0 ;
}
