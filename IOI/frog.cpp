#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
using namespace std ;
#define par pair<int,int>
#define r first
#define c second
const int lim = 5005 ;
const int inf = (1<<30) ;


int N ;
par arr[lim] ;
map <int,int> dp[lim] ;


int main() {
    int res = 0 ;
    map <int,int> :: iterator it, it2 ;

    scanf("%d", &N ) ;
    scanf("%d", &N ) ;
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%d%d", &arr[i].r, &arr[i].c ) ;

    sort( arr, arr+N ) ;
    for( int i=0; i<N; i++ ) {

        for( int j=0, pend, a, b; j<i; j++ ) {
            if( arr[i].r==arr[j].r ) {
                pend = 0 ;
            }
            else if( arr[i].c==arr[j].c ) {
                pend = inf ;
            }
            else {
                pend = (arr[i].r-arr[j].r)*lim  +  abs(arr[i].c-arr[j].c) ;
                if( arr[i].c < arr[j].c )
                    pend *= -1 ;
            }

            it = dp[j].find( pend ) ;
            if( it==dp[j].end()  )
                a = 2 ;
            else
                a = it->c +1 ;

            res = max( res, a ) ;
            it2 = dp[i].find(pend) ;
            if( it2==dp[i].end() )
                dp[i][pend] = a ;
            else
                it2 -> c = max( it->c, a );

        }
    }

    if( res<3 )
        res = 0 ;

    printf("%d\n", res ) ;

    return 0 ;
}
