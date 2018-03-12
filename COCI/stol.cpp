#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
const int lim = 405 ;

int main() {
    int N, M ;
    char S[lim][lim] ;
    int carg[lim][lim] ;
    int res = 0 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=1; i<=N; i++ ) {
        scanf("%s", S[i] ) ;
        for( int j=1; j<=M; j++ ) {
            carg[i][j] = carg[i][j-1] ;
            if( S[i][j-1]=='X' )
                carg[i][j] ++ ;
        }
    }

    for( int a=1; a<=M; a++ ) {
        for( int b=a; b<=M; b++ ) {
            for( int i=1, X=0, w=b-a+1; i<=N; i++ ) {
                if( carg[i][b]-carg[i][a-1] ) {
                    X = 0 ;
                }
                else {
                    X ++ ;
                    res = max( res, w+X ) ;
                    //cout << a << " " << b << " " << i << " -> " << X << endl ;
                }
            }
        }
    }

    cout << max( 0, res*2-1 ) << endl ;

    return 0 ;
}
