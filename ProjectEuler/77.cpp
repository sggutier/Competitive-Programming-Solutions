#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000005

int P=0 ;
int primos[lim], comp[lim] ;

int dp[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim; j+=i )
                comp[j] = 1 ;

    for( int i=2; i<lim; i++ )
        if( !comp[i] )
            primos[P++] = i ;

}

int main() {
    int N ;
    int res = 0 ;

    criba() ;

    cout << P << endl ;
    cin >> N ;
    dp[0] = 1 ;
    for( int i=0; i<P; i++ ) {
        for( int j=0; j+primos[i]<=N; j++ )
            dp[j+primos[i]] += dp[j] ;
    }

    for( int i=0; i<=N; i++ ) {
        if( dp[i]>5000 ) {
            cout << i << " " << dp[i] << endl ;
            return 0 ;
        }
    }

    cout << "Nope. Chuck Testa." << endl ;

    return 0 ;
}
