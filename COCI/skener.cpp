#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int N, M, X, Y ;
    char S[100][100] ;

    cin >> N >> M >> X >> Y ;
    for( int i=0; i<N; i++ )
        cin >> S[i] ;

    for( int i=0; i<N; i++ ) {
        for( int r=0; r<X; r++ ) {
            for( int j=0; j<M; j++ ) {
                for( int c=0; c<Y; c++ ) {
                    printf("%c", S[i][j] ) ;
                }
            }
            printf("\n" ) ;
        }
    }

    return 0 ;
}
