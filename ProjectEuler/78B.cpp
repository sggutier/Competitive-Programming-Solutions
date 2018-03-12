#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 22005
#define mod 1000000LL

int N ;
int dp[mod] ;
bool usd[mod] ;

int main() {
    int N, K ;

    cin >> N ;

    dp[0] = 1 ;
    for( int j=1; j<=N; j++ ) {
        for( int i=j; i<=N; i++ ) {
            dp[i] = (dp[i]+dp[i-j])%mod ;
        }
        cout << j << " " << dp[j] << endl ;
        if( dp[j]==0 ) {
            K = j ;
            break ;
        }
    }

    cout << K << endl ;

    return 0 ;
}


