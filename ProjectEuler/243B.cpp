#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;
#define lim 10000005

int P = 0 ;
long long primos[lim] ;
bool comp[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
        if( !comp[i] )
            for( int j=i*i; j<lim; j+=i )
                comp[j] = 1 ;
    for( int i=2; i<lim; i++ ) {
        if( !comp[i] ) {
            primos[P++] = i*1LL ;
            if( P<=50 )
                printf("%d ", i ) ;
        }
    }
    printf("\n" ) ;
}

long long tot(long long N) {
    long long res = N ;
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
    long long W = 4LL ;
    long double res = 15499.0/94744.0, q=(1LL<<60)*1.0 ;
    //double res = 1.0/2.0 ;

    criba() ;

    cout << tot(48) << endl ;

    cin >> N ;
    for( int i=0; i<N; i++ ) {
        W *= primos[i] ;
        long long a = tot(W) ;
        q = min( q, (long double)((1.0*a)/(W-1.0)) ) ;
        printf("%lld %lld -> %.15lf %.15lf\n", a, W, double(res), double(q) ) ;
        if( q+0.0000000000001<res ) {
            printf("---->>>>%d\n", i ) ;
            printf("%d\n", primos[i] ) ;
            return 0 ;
        }
    }

    return 0 ;
}
