#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 37

long long pasc[lim][lim] ;

void hazTrian() {
    for( int i=0; i<lim; i++ ) {
        pasc[i][0] = 1LL ;
        pasc[i][i] = 1LL ;
        for( int j=1; j<i; j++ )
            pasc[i][j] = pasc[i-1][j] + pasc[i-1][j-1] ;
    }
}

int main() {
    int N ;
    long long fact[10] ;

    fact[0] = 1LL ;
    for( int i=1; i<10; i++ )
        fact[i] = fact[i-1]*i ;
    hazTrian() ;

    scanf("%d",&N) ;
    while( N ) {
        long long res = pasc[N*N][N] ;
        res -= fact[N] ;
        cout << res << endl ;
        scanf("%d",&N) ;
    }

    return 0 ;
}
