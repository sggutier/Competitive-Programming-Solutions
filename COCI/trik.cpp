#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std ;

int main() {
    int arr[] = { 1, 0, 0 } ;
    string S ;

    cin >> S ;

    for( int i=0; i<S.size(); i++ ) {
        if( S[i]=='A' )
            swap( arr[0], arr[1] ) ;
        else if( S[i]=='B' )
            swap( arr[2], arr[1] ) ;
        else if( S[i]=='C' )
            swap( arr[0], arr[2] ) ;
    }

    if( arr[0] )
        cout << 1 << endl ;
    else if( arr[1] )
        cout << 2 << endl ;
    else
        cout << 3 << endl ;

    return 0 ;
}
