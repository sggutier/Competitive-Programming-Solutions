#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
    int N ;
    long long sum=0LL, sImp=0LL, minImp=(1LL<<60) ;

    cin >> N ;
    for( int i=0; i<N; i++ ) {
        long long tmp ;
        cin >> tmp ;
        if( tmp%2 ) {
            sImp += tmp ;
            minImp = min( minImp, tmp ) ;
        }
        else {
            sum += tmp ;
        }
    }

    if( sImp && sImp%2==0 )
        sImp -= minImp ;
    if( sImp==0 )
        sum = 0 ;

    cout << sImp + sum << endl ;

    return 0 ;
}
