#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000006

int N, mod ;
int dp[lim][3][3] ;
char S[lim] ;

int main() {
    int res = 1 ;

    scanf("%d%d", &N, &mod ) ;
    scanf("%s", S ) ;

    for( int i=0; i<3; i++ )
        for( int j=0; j<3; j++ )
            dp[N][i][j] = 1 ;

    for( int i=N-1; i>=0; i-- ) {
        for( int sum=0; sum<3; sum++ ) {
            for( int act=0; act<=sum; act++ ) {

                if( act ) {
                    dp[i][sum][act] = dp[i+1][sum][act-1] ;
                }
                else if( sum<2 ){
                    dp[i][sum][act] = dp[i+1][sum+1][act] ;
                }
                if( act<sum ) {
                    dp[i][sum][act] = ( dp[i][sum][act]  +  dp[i+1][sum][act+1]   ) %  mod ;
                }
                else if( sum<2 ) {
                    dp[i][sum][act] = ( dp[i][sum][act]  +  dp[i+1][sum+1][act+1]   ) %  mod ;
                }

            }
        }
    }

    for( int i=0, act=0, sum=0; i<N; i++ ) {
        if( S[i]=='L' ) {
            if( act ) {
                act -- ;
            }
            else {
                sum ++ ;
            }
        }
        else {
            if( act ) {
                //cout << "->" << i+1 << " " << sum << " "<< act-1 << endl ;
                //cout << dp[i+1][sum][act-1] << endl ;
                res = ( res + dp[i+1][sum][act-1]   ) %  mod ;
            }
            else if( sum<2 ) {
                //cout << "->" << i+1 << " " << sum+1 << " "<< act << endl ;
                //cout << dp[i+1][sum+1][act] << endl ;
                res = ( res  +  dp[i+1][sum+1][act]   ) %  mod ;
            }

            if( act<sum )
                act ++ ;
            else {
                sum ++ ;
                act ++ ;
            }
        }
        //printf("%d %d %d\n", i, sum, act ) ;
    }

    printf("%d\n", res%mod ) ;

    return 0 ;
}
