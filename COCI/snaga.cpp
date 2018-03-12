#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;


int N ;
long long num[100], forc[100] ;


long long mcd( long long A, long long B ) {
    long long C ;

    while( B ) {
        C = A%B ;
        A = B ;
        B = C ;
    }

    return A ;
}

long long mcm( long long A, long long B ) {
    return (A/mcd(A,B))*B ;
}

void carga() {
    const long long T = 100000000000000000LL ;
    long long A=1LL, B=1LL, ult ;
    int arr[100] ;

    arr[2] = 2 ;
    for( int i=3; i<50; i++ ) {
        for( int j=1; ; j++ ) {
            if( i%j ) {
                arr[i] = arr[j]+1 ;
                break ;
            }
        }
    }

    N = 0 ;
    forc[N] = 2LL ;
    num[N++] = 1LL ;
    ult = 2LL ;
    for( int i=2; A<T; i++ ) {
        A = mcm( A, i ) ;
        if( A==B )
            continue ;
        int j ;
        for( j=2; A%j==0; j++ ) ;
        num[N] = A ;
        forc[N] = forc[N-1]*(A/B) - ult + arr[j]+0LL ;
        ult = arr[j] + 0LL ;
        N ++ ;
        B = A ;
    }
}

long long calc( long long W ) {
    long long res = -4LL ;

    for( int i=N-1; i>=0; i-- ) {
        res += forc[i]*(W/num[i]) ;
        W %= num[i] ;
    }

    return res ;
}

int main() {
    long long A, B ;

    carga() ;

    cin >> A >> B ;

    cout << calc(B)-calc(A-1) << endl ;

    return 0 ;
}
