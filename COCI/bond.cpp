#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std ;
const int lim = 20 ;
const int lim2 = 1<<20 ;

int N ;
double arr[lim][lim] ;
double dp[2][lim2] ;
bool usd[2][lim2] ;

int main() {
    queue <int> Q[2] ;
    int act=0, sig=1 ;
    const double cero = 1.0*0 ;

    scanf("%d", &N ) ;

    for( int i=0; i<N; i++ ) {
        for( int j=0, tmp; j<N; j++ ) {
            scanf("%d", &tmp ) ;
            arr[i][j] = tmp/100.0 ;
        }
    }

    for( int i=0; i<2; i++ ) {
        for( int j=0; j<lim2; j++ )
            dp[i][j] = cero ;
    }

    Q[act].push( 0  ) ;
    dp[act][0] = 1.0 ;

    for( int i=0; i<N; i++, swap(act,sig)  ) {

        while( !Q[act].empty() ) {
            int pos=Q[act].front() ;
            Q[act].pop() ;

            for( int j=0; j<N; j++ ) {
                if( (1<<j) & pos )
                    continue ;
                dp[sig][pos | (1<<j)] = max( dp[sig][pos | (1<<j)],  dp[act][pos]*arr[i][j]   ) ;
                if( !usd[sig][ pos | (1<<j) ]  ) {
                    Q[sig].push( pos | (1<<j) ) ;
                    usd[sig][ pos | (1<<j) ] = 1 ;
                }
            }
            usd[act][pos] = 0 ;
            dp[act][pos] = cero ;
        }

    }

    printf("%.12lf\n", dp[act][(1<<N)-1]*100 ) ;

    return 0 ;
}
