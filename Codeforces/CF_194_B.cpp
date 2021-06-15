#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

long long mcd( long long a, long long b ) {
    long long c ;

    while( b ) {
        c = a%b ;
        a = b ;
        b = c ;
    }

    return a ;
}

int main() {
    int N ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        long long a, b ;
        cin >> a ;
        b = mcd( 4LL*a, a+1LL ) ;
        cout << (4LL*a)/b + 1LL << endl ;
    }

    return 0 ;
}
