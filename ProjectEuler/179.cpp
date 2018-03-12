#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 10000007
#define lim2 3200

int P=0 ;
int primos[lim2], comp[lim2] ;
int D[lim] ;

void criba() {
    for( int i=2; i*i<lim2; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim2; j+=i )
                comp[j] = 1 ;
    for( int i=2; i<lim2; i++ )
        if( !comp[i] )
            primos[P++] = i ;
}

int numDiv(int N) {
    int res = 1, tmp ;
    for( int i=0; i<P; i++ ) {
        int tmp = 1 ;
        while( N%primos[i]==0 ) {
            tmp ++ ;
            N /= primos[i] ;
        }
        res *= tmp ;
    }
    if( N>1 ) {
        tmp = sqrt(N) ;
        if( tmp*tmp==N )
            res *= 3 ;
        else
            res *= 2 ;
    }
    return res ;
}

int main() {
    int N ;
    int res = 0 ;

    criba() ;

    cin >> N ;
    D[1] = 1 ;
    for( int i=2; i<=N; i++ ) {
        D[i] = numDiv(i) ;
        if( D[i]==D[i-1] )
            res ++ ;
            //cout << i << " " << i-1 << " " << D[i] << " " << D[i-1] << endl  ;
    }

    cout << res << endl ;

    return 0 ;
}
