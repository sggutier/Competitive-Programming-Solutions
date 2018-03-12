#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std ;
#define lim 305

int N ;
int arr[lim][lim] ;
int dp[lim][lim][2] ;

int main() {
    int act=0, sig=1 ;
    int res = -(1<<30) ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        for( int j=0; j<N; j++ )
            scanf("%d", &arr[i][j] ) ;

    if( N==1 ) {
        printf("%d\n", arr[0][0] ) ;
        return 0 ;
    }

    for( int j=N-1, sum=0; j>=0; j-- ) {
        sum += arr[N-1][j] ;
        for( int k=j; k<N; k++ )
            dp[j][k][sig] = sum ;
    }

    for( int i=N-2; i>0; i-- ) {
        for( int j=N-1; j>=0; j-- ) {
            for( int k=N-1, sum=-(1<<30); k>=j; k-- ) {

                if( k>j ) {
                    sum = max( sum, dp[j][k][sig] ) ;
                    sum += arr[i][k] ;
                    dp[j][k][act] = arr[i][j] + sum ;
                    dp[j][k][act] = max( dp[j][k][act],  dp[j+1][k  ][act] + arr[i][j] ) ;
                }
                else {
                    sum = max( sum, dp[j][k][sig] ) ;
                    dp[j][k][act] = arr[i][j] + sum ;
                    if( k+1<N )
                        dp[j][k][act] = max( dp[j][k][act],  dp[j  ][k+1][act] ) ;
                }
            }

        }
        swap( act, sig ) ;
    }
    for( int i=0, sum=0; i<N; i++ ) {
        sum += arr[0][i] ;
        for( int j=0; j<=i; j++ )
            res = max( res, sum + dp[j][i][sig] ) ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
