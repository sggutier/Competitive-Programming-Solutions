#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int T, N ;

    cin >> T ;
    for( int i=0; i<T; i++ ) {
        long long carg = 0LL ;
        cin >> N ;
        for( int j=1; j*j<=N; j++ ) {
            if( N%j==0 ) {
                if( j*j!=N && j!=1 ) {
                    carg += j ;
                    carg += N/j ;
                }
                else if( j!=N )
                    carg += j ;
            }
        }
        cout << carg << endl ;
    }

    return 0 ;
}
