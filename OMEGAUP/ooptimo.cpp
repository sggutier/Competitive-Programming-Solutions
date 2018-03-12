#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std ;
#define lim 362885
#define par pair<int,int>
#define f first
#define s second

int N ;
char rVal[1<<9][9], rValInv[1<<9][9] ;
int fact[10] ;
priority_queue <par> Q ;
int cost[10][10], minP[lim] ;
char usd[lim] ;

int precargAnt() {
    for( int b=0; b<(1<<N); b++ ) {
        for( int i=0; i<N; i++ ) {
            if( (1<<i) & b )
                continue ;
            rVal[b][i] = i ;
            for( int j=0; j<i; j++ )
                if( (1<<j) & b )
                    rVal[b][i] -- ;
            rValInv[b][ rVal[b][i] ] = i ;
        }
    }
    fact[1] = 1 ;
    fact[0] = 1 ;
    for( int i=2; i<N; i++ )
        fact[i] = fact[i-1]*i ;
}

int permToI( char S[] ) {
    int res = 0 ;
    for( int i=0, b=0; i<N; b+=(1<<S[i]), i++ ) {
        res += fact[N-i-1]*rVal[b][S[i]] ;
    }
    return res ;
}

void iToPerm( int W, char S[] ) {
    int tmp ;
    for( int i=0, b=0; i<N; i++, b+=(1<<tmp) ) {
        tmp = rValInv[b][ W/fact[N-i-1] ] ;
        W %= fact[N-i-1] ;
        S[i] = tmp ;
    }
}

int main() {
    int W, pos, T ;
    char S[11] ;
    par tmp ;


    scanf("%d", &N ) ;
    for( int i=0; i<N; S[i++]-- )
        scanf("%d", &S[i] ) ;
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<i; j++ )  {
            scanf("%d", &cost[i][j] ) ;
            cost[j][i] = cost[i][j] ;
        }
    }
    precargAnt() ;

    W = permToI(S) ;
    Q.push( par(-1,W) ) ;
    while( !Q.empty() ) {
        tmp = Q.top() ;
        pos = tmp.s ;
        T = tmp.f;
        Q.pop() ;

        if( usd[pos] )
            continue ;
        if( pos==0 ) {
            printf("%d\n", -(T+1) ) ;
            return 0 ;
        }

        usd[pos] = 1 ;
        iToPerm(pos,S) ;

        for( int i=0; i<N; i++ ) {
            for( int j=i+1; j<N; j++ ) {
                swap( S[i], S[j] ) ;

                W = permToI(S) ;
                if( !minP[W] || T-cost[i][j]>minP[W] ) {
                    Q.push( par(T-cost[i][j],W) ) ;
                    minP[W] = T-cost[i][j] ;
                }

                swap( S[i], S[j] ) ;
            }
        }
    }

    return 0 ;
}

