#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 100005

int P = 0 ;
long long primos[lim] ;
bool comp[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim; j+=i )
                comp[j] = 1 ;
    for( int i=2; i<lim; i++ )
        if( !comp[i] )
            primos[P++] = i*1LL ;
}

long long tot(long long N) {
    long long res = N*1LL ;
    for( int i=0; i<P; i++ ) {
        if( N%primos[i]==0 ) {
            res = (res*(primos[i]-1))/primos[i] ;
        }
        while( N%primos[i]==0 ) {
            N /= primos[i] ;
        }
    }
    if( N>1 ) {
        cout << N << endl ;
        int W = int(sqrt(N)) ;
        if( W*W==N )
            res = (res*(W-1))/W ;
        else
            res = (res*(N-1))/N ;
    }
    return res ;
}

int main() {
    long long N ;
    double res = 15499.0/94744.0, q=(1<<30)*1.0 ;
    //double res = 1.0/2.0 ;

    criba() ;

    cin >> N ;
    for( long long i=2; i<=N; i++ ) {
        long long a = tot(i) ;
        q = min( q, (1.0*a)/i ) ;
        printf("%lld %lld -> %lf %lf\n", a, i, res, q ) ;
        if( q<res ) {
            printf("---->>>>%d\n", i ) ;
            return 0 ;
        }
    }

    return 0 ;
}
