#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = 1e9 ;
const int limN = 1e4 ;
const int limM = 1e2 ;

int N, M ;
int dp[limM][limN] ;
int arr[limM] ;

void caso() {
    scanf("%d", &M ) ;
    memset( dp, 0, sizeof(dp) );

    dp[0][0] = -1 ;
    for( int i=1; i<=M; i++ ) {
        scanf("%d", &arr[i] ) ;
        for( int j=N; j>=0; j-- )
            dp[i][j] = dp[i-1][j] ;
        for( int j=N; j>=arr[i]; j-- ) {
            if( !dp[i][j] and dp[i-1][j-arr[i]] )
                dp[i][j] = i ;
        }
    }


    for( int pos=N; pos>=0; pos-- )  {
        if( !dp[M][pos] )
            continue ;
        int i = dp[M][pos], res=pos ;
        do {
            printf("%d ", arr[i] ) ;
            pos = pos-arr[i] ;
            i = dp[i][pos] ;
        } while( pos ) ;
        printf("sum:%d\n", res ) ;
        break ;
    }
}

int main() {
    while( scanf("%d", &N)!=EOF )
        caso() ;
    
    return 0 ;
}
