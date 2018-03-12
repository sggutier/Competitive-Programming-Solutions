#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int r4( int X ) {
    for( int i=3; ; i+=2 ) {
        int tmp ;
        if( ((i*i)/2) >= X )
            return i ;
    }
}

int r1( int X ) {
    for( int i=1; ; i+=2 ) {
        if( ((i*i-1)/2) +1 >= X )
            return i ;
    }
}

int r2( int X ) {
    for( int i=1; ; i+=2 ) {
        if( ((i*i-1)/2) >= X )
            return i ;
    }
}

int r3( int X ) {
    X -- ;
    return r2(X) ;
}

int main() {
    int X ;

    cin >> X ;

    if( X%4==0 )
        cout << r4(X) << endl ;
    else if( X%4==1 )
        cout << r1(X) << endl ;
    else if( X%4==2 )
        cout << r2(X) << endl ;
    else if( X%4==3 )
        cout << r3(X) << endl ;

    return 0 ;
}

