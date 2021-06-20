#include <algorithm>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std ;

bool mult( string S ) {
    int carg[2] = {0,0} ;
    for( int i=S.size()-1; i>=0; i-- ) {
        carg[i%2] += S[i]-'0' ;
    }
    return carg[0]%11==carg[1]%11 ;
}

int main() {
    string A ;

    cin >> A ;
    while( A.size()!=1 || A[0]!='0' ) {
        cout << A << " is" ;
        if( !mult(A) )
            cout << " not" ;
        cout << " a multiple of 11." << endl ;
        cin >> A ;
    }

    return 0 ;
}
