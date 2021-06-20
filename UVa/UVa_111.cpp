#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 32

int main() {

    int N ;
    int p[lim], arr[lim], dp[lim] ;
    int res, a ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &a ) ;
        p[i] = a-1 ;
    }
    while( scanf("%d", &a ) != EOF    )   {
        arr[a-1] = 0 ;
        for( int i=1; i<N; i++ ) {
            scanf("%d", &a ) ;
            arr[a-1] = i ;
		}		
		res = 0 ;
        for( int i=0; i<N; i++ ) {
            dp[i] = 0 ;
            for( int j=0; j<i; j++  )
                if( p[ arr[j] ] < p[ arr[i]  ]   )
                    dp[i] = max( dp[j], dp[i]  )  ;
            dp[i] ++ ;
            res = max( res, dp[i] ) ;
        }
        printf("%d\n", res ) ;
    }

    return 0 ;
}
