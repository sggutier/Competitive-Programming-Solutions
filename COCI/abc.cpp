#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std ;

int main() {
    int arr[3] ;
    string A, B="ABC" ;

    for( int i=0; i<3; i++ )
        cin >> arr[i] ;
    cin >> A ;

    sort( arr, arr+3 ) ;
    while( A!=B ) {
        next_permutation( arr, arr+3 ) ;
        next_permutation( B.begin(), B.end() ) ;
    }

    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl ;

    return 0 ;
}
