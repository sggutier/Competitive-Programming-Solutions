#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std ;

int main() {
    long long N ;
    long long res = 0LL ;

    cin >> N ;

    for( long long A=3LL; A*3LL <= N;  A+=2LL  ) {
        long long B = (A+1LL)/2LL, C ;
        C = sqrt( A*A  -  B*B ) ;
        if( C*C + B*B  ==   A*A   &&  C>0LL )
            res += A*3LL + 1LL ;

        B = (A-1LL)/2LL ;
        C = sqrt( A*A  -  B*B ) ;
        if( C*C + B*B  ==   A*A   && C>0LL   )
            res += A*3LL - 1LL ;
    }

    cout << res << endl ;

    return 0 ;
}
