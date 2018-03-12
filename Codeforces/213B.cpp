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
#define mod 1000000007LL
#define lim 105

int N ;
int cpy[11], arr[11] ;
long long res=0LL ;
long long dp[lim][10], trian[lim][lim] ;
bool usd[lim][10] ;

void pasc() {
    trian[0][0] = 1LL ;
    for( int i=1; i<lim; i++ ) {
        trian[i][0] = 1LL ;
        for( int j=1; j<=i; j++ )
            trian[i][j] = (trian[i-1][j] + trian[i-1][j-1])%mod ;
    }
}

long long memo( int res, int pos ) {
    if( usd[res][pos] )
        return dp[res][pos] ;
    usd[res][pos] = 1 ;
    if( pos==9 ) {
        if( arr[pos]<=res )
            return dp[res][pos] = 1LL ;
        return dp[res][pos] = 0LL ;
    }

    dp[res][pos] = 0LL ;
    for( int i=arr[pos]; i<=res; i++  ) {
        dp[res][pos] = ( (    (trian[res][i]*memo(res-i,pos+1) )%mod   )+dp[res][pos] )%mod ;
    }

    return dp[res][pos] ;
}

int main() {
    pasc() ;

    scanf("%d", &N ) ;
    for( int i=0; i<10; i++ )
        scanf("%d", &cpy[i] ) ;

    for( int i=1; i<=N; i++ ) {
        for( int d=1; d<10; d++ ) {

            memset( usd, 0, sizeof(usd)  ) ;
            for( int j=0; j<10; j++ )
                arr[j] = cpy[j] ;
            arr[d] = max( 0, arr[d]-1 ) ;

            res = (res+memo( i-1, 0 )   )%mod  ;

        }
    }

    cout << res << endl ;

    return 0 ;
}
