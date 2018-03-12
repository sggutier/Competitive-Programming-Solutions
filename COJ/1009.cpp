#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    long long N ;

    cin >> N ;

    if( N>0 )
        cout << (N*(N+1))/2 << endl ;
    else {
        N *= -1 ;
        cout << -((N*(N+1))/2)+1 << endl ;
    }

    return 0 ;
}
