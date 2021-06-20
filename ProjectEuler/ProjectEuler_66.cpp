#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std ;
#define par pair< long long , long long >
#define f   first
#define s   second

long long mcd( long long A, long long B ) {
    long long C ;
    while( B ) {
        C = A%B ;
        A = B ;
        B = C ;
    }
    return A ;
}

par sumaF( par A, par B ) {

    par res = par( A.f*B.s  +  B.f*A.s,  A.s*B.s ) ;
    int tmp = mcd( res.f, res.s ) ;
    res.f /= tmp ;
    res.s /= tmp ;
    return res ;
}

long long pell( long long D ) {
    long long a, b ;
    par res ;

    a = 1LL ;
    b = a+1LL ;

    do {
        res = par( a, 1LL ) ;
        while( res.f*res.f - res.s*res.s*D != 1LL  && res.f<1000000000000LL )  {
            res = sumaF( res,   sumaF(  par(-res.f,res.s*2LL) ,  par(D *res.s,res.f*2LL)  )  ) ;
        }
        a ++ ;
        if( res.f*res.f - res.s*res.s*D == 1LL )
            return res.f ;
        if( res.s*res.s - res.f*res.f*D == 1LL )
            return res.s ;
    } while( 1  ) ;

    return res.f ;
}

int main() {
    long long D, tmp ;
    long long res = 0LL ;

    for( D=1LL; D<=1000LL; D++ ) {
        tmp = (long long) sqrt(D) ;
        if( tmp*tmp == D )
            continue ;
        cout << D << " " ;
        cout << tmp << " -> " ;
        cout << pell(D) << endl ;
        res = max( res, pell(D) ) ;
    }

    cout << res << endl ;

    return 0 ;
}
