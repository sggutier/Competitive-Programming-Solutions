#include <algorithm>
#include <cstdio>
#include <list>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 105
#define par pair<int,int>
#define f first
#define s second

int N, K ;
list <int> adj[lim] ;
int arb[lim] ;
int disProf[lim] ;
par padre[lim] ;
int hijo[lim], bro[lim] ;
int dp[lim][lim][lim], usd[lim][lim][lim] ;

int memo( int pos, int raiz, int carg ) {
    if( usd[pos][raiz][carg] )
        return dp[pos][raiz][carg] ;
    usd[pos][raiz][carg] = 1 ;
    dp[pos][raiz][carg] = (1<<30) ;
    disProf[pos] = disProf[ padre[pos].s ] + padre[pos].f ;

    //printf("%d %d %d -> %d\n", pos, raiz, carg, disProf[pos] ) ;

    for( int i=0; i<=carg; i++ ) {
        int a=0, b=0 ;

        if( hijo[pos] )
            a = memo( hijo[pos], raiz, i ) ;
        if( bro[pos] )
            b = memo( bro[pos], raiz, carg-i ) ;
        dp[pos][raiz][carg] = min( dp[pos][raiz][carg], a+b+arb[pos]*(disProf[pos]-disProf[raiz])  ) ;
    }
    for( int i=0; i<carg; i++ ) {
        int a=0, b=0 ;

        if( hijo[pos] )
            a = memo( hijo[pos], pos, i ) ;
        if( bro[pos] )
            b = memo( bro[pos], raiz, carg-i-1 ) ;
        dp[pos][raiz][carg] = min( dp[pos][raiz][carg], a+b ) ;
    }

    return dp[pos][raiz][carg] ;
}

int main() {
    scanf("%d%d", &N, &K ) ;
    for( int i=1; i<=N; i++ ) {
        int a, b, c ;
        scanf("%d%d%d", &a, &b, &c ) ;
        arb[i] = a ;
        padre[i] = par( c, b ) ;

        if( adj[b].size()==0 ) {
            hijo[b] = i ;
        }
        else {
            list <int> :: iterator it = adj[b].end() ;
            it -- ;
            bro[ *it ] = i ;
        }
        adj[b].push_back( i ) ;
    }

    printf("%d\n", memo( *adj[0].begin() ,0,K) ) ;

    return 0 ;
}
