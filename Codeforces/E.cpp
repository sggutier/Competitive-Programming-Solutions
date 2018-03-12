#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
#define lim 100005

int N ;
int arr[lim] ;
long long le[lim], ro[lim], dp[lim] ;

int main() {
    long long res = 0LL ;

    scanf("%d", &N ) ;
    N -- ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;

    for( int i=N-1; i>=0; i-- ) {
        if( arr[i]==1 ) {
            ro[i] = 0LL ;
            continue ;
        }
        ro[i] = 0LL + arr[i]- arr[i]%2 + ro[i+1] ;
    }
    for( int i=0; i<N; i++ ) {
        if( arr[i]==1 ) {
            le[i] = 0LL ;
            continue ;
        }
        if( i )
            le[i] = 0LL + arr[i]- arr[i]%2 + le[i-1] ;
        else
            le[i] = 0LL + arr[i]- arr[i]%2 ;
    }

    for( int i=N-1; i>=0; i-- ) {
        dp[i] = max( 0LL + dp[i+1] + arr[i]- (arr[i]+1)%2, ro[i] ) ;
        if( i )
            res = max( res, dp[i] + le[i-1] ) ;
        else
            res = max( res, dp[i] ) ;
    }

    cout << res << endl ;


    return 0 ;
}
