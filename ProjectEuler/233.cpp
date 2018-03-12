#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;

int pts( long long D ) {
    int res = 0 ;
    D *= D ;
    for( long long i=1LL; i*i<=D; i++ ) {
        long long a, b, c ;
        a = i*i ;
        b = D-a ;
        c = sqrt(b) ;
        if( c*c==b )
            res += 4 ;
    }
    return res ;
}

int main() {
    int res = 0 ;
    int N ;

    cin >> N ;
    for( int i=1; i<=N; i++ ) {
        if( pts( (long long) (i)   )  ==  420 )  {
            printf("%d\n", i ) ;
            res ++ ;
        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
