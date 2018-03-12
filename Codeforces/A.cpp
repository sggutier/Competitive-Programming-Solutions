#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int N ;
string S, res = "" ;

bool pal( string W ) {
    for( int i=0, j=W.size()-1; i<j; i++, j-- )
        if( W[i] != W[j] )
            return 0 ;

    return 1 ;
}

int main() {
    string tmp ;

    cin >> S ;

    N = S.size() ;

    for( int b=0; b<(1<<N); b++ ) {
        tmp = "" ;
        for( int i=0; i<N; i++ )
            if( (1<<i) & b )
                tmp += S[i] ;
        if( pal(tmp) )
            res = max( res, tmp ) ;
    }

    cout << res << endl ;

    return 0 ;
}
