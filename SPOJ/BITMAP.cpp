#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 200

int N, M ;
char S[lim][lim] ;
int dis[lim][lim] ;

void caso() {
    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", S[i] ) ;
        for( int j=0, ult=-1; j<M; j++ ) {
            if( S[i][j]=='1' )
                ult = j ;
            if( ult>=0 )
                dis[i][j] = j-ult ;
            else
                dis[i][j] = (1<<30) ;
        }
        for( int j=M-1, ult=-1; j>=0; j-- ) {
            if( S[i][j]=='1' )
                ult = j ;
            if( ult>=0 )
                dis[i][j] = min( dis[i][j], ult-j ) ;
        }
    }

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            int res = (1<<30) ;
            for( int k=0; k<N; k++ )
                res = min( res, abs(i-k) + dis[k][j] ) ;
            printf("%d ", res ) ;
            //printf("%d ", dis[i][j] ) ;
        }
        printf("\n" ) ;
    }
}

int main() {
    int T ;

    for( scanf("%d", &T ); T; T-- )
        caso() ;

    return 0 ;
}
