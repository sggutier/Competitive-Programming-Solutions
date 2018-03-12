#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;

int N, M ;
char calif[300][300] ;
int maxC[300] ;

int main() {
    int res = 0, buen ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", calif[i] ) ;
        for( int j=0; j<M; j++ )
            maxC[j] = max( maxC[j], int(calif[i][j]) ) ;
    }

    for( int i=0; i<N; i++ ) {
        buen = 0 ;
        for( int j=0; j<M; j++ ) {
            if( calif[i][j] ==  maxC[j] )
                buen = 1 ;
        }
        res += buen ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
