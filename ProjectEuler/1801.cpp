#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 105

int main() {
    int N, M ;
    char S[lim][lim] ;
    int res = 0 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", S[i] ) ;
    }

    for( int i=0; i<N; i++ ) {
        int cnt = 0 ;
        for( int j=0; j<M; j++ ) {
            if( S[i][j]!='.' ) {
                cnt ++ ;
            }
            else {
                if( cnt%2==1 )
                    res += 2 ;
            }
        }
        res += cnt ;
    }

    printf("%d\n", res/2 ) ;

    return 0 ;
}
