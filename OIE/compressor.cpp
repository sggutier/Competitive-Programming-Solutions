#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int N, numRes=0 ;
string S, res ;
char arr[100] ;

int main() {
    gets(arr) ;
    S = arr ;
    N = strlen(arr) ;

    for( int i=0; i<N; i++ ) {
        for( int j=1; i+j<=N; j++ ) {
            string tmp = S.substr( i, j ) ;
            int k, w=0 ;
            for( k=0; k+j<=N; k++ ) {
                if( S.substr(k,j)==tmp ) {
                    w ++ ;
                    k += j-1 ;
                }
            }
            if( w>1 && j>numRes ) {
                numRes = j ;
                res = tmp ;
            }
        }
    }

    cout << res << endl ;

    return 0 ;
}
