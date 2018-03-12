#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std ;

int main() {
    string org[4] = {   "ABCD",
                        "EFGH",
                        "IJKL",
                        "MNO." } ;
    string arr[4] ;
    int N=4 ;
    int res = 0 ;

    for( int i=0; i<N; i++ )
        cin >> arr[i] ;

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<N; j++ ) {
            if( arr[i][j]=='.' )
                continue ;
            for( int r=0; r<N; r++ ) {
                for( int c=0; c<N; c++ ) {
                    if( arr[i][j]==org[r][c] )
                        res += abs(i-r) + abs(j-c) ;
                }
            }
        }
    }

    cout << res << endl ;

    return 0 ;
}
