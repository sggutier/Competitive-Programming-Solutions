#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 22005
#define mod 1000000LL

int N ;
int dp[lim][lim] ;
bool usd[mod] ;

int main() {
    int N, K=0 ;

    cin >> N ;

    dp[0][0] = 1 ;
    for( int i=1; i<=N; i++ ) {
        printf("%2d ", i ) ;
        for( int j=1; j<=i; j++ ) {
            dp[i][j] = (dp[i][j-1] + dp[i-j][ min(i-j,j) ])%mod ;
            printf("%3d ", dp[i][j] ) ;
        }
        cout << endl ;
        if( !usd[dp[i][i]] ) {
            usd[dp[i][i]] = 1 ;
            K ++ ;
        }
        if( dp[i][i]==0 ) {
            return 0 ;
        }
    }


    cout << K << endl ;



    return 0 ;
}


