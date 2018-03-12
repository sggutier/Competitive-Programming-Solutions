#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000

int N, M ;
int dp[lim][lim], arr[lim][lim] ;

int main() {
    freopen( "matrix.txt", "r", stdin ) ;

    int res = (1<<30) ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            scanf("%d", &arr[i][j] ) ;
            dp[i][j] = (1<<30) ;
        }
        dp[i][0] = arr[i][0] ;
    }

    for( int j=0; j<M; j++ ) {
        int carg = 0 ;
        for( int a=0; a<N; a++ ) {
            carg = dp[a][j] ;
            dp[a][j+1] = min( dp[a][j+1], carg+arr[a][j+1] ) ;
            for( int b=a+1; b<N; b++ ) {
                carg += arr[b][j] ;
                dp[b][j+1] = min( dp[b][j+1], carg+arr[b][j+1] ) ;
            }
            carg = dp[a][j] ;
            for( int b=a-1; b>=0; b-- ) {
                carg += arr[b][j] ;
                dp[b][j+1] = min( dp[b][j+1], carg+arr[b][j+1] ) ;
            }
        }
    }

    for( int i=0; i<N; i++ )
        res = min( res, dp[i][M-1] ) ;

    printf("%d\n", res ) ;

    return 0 ;
}
