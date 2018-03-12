#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std ;
#define lim 300005
#define par pair<int,int>
#define f first
#define s second

int N, K ;
int arr[lim], usd[lim] ;
char mapa[lim] ;
priority_queue <par> Q ;

int main() {
    int res = 0, res2 = 1, tele=0 ;

    scanf("%d%d", &N, &K ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;
    scanf("%s", mapa ) ;
    K -- ;

    for( int i=K; i>=0; i-- ) {
        if( arr[i]>arr[i+1] ) {
            break ;
        }
        res2 = max( res2, K-i+1 ) ;
        if( mapa[i]=='T' )
            tele = 1 ;
    }
    for( int i=K; i<N; i++ ) {
        if( arr[i]>arr[i-1] ) {
            break ;
        }
        res2 = max( res2, i-K+1 ) ;
        if( mapa[i]=='T' )
            tele = 1 ;
    }

    if( !tele ) {
        printf("%d\n", res2 ) ;
        return 0 ;
    }

    for( int i=0; i<N; i++ ) {
        if( mapa[i]=='T' )
            Q.push( par(-arr[i],i) ) ;
    }
    while( !Q.empty() ) {
        int pos = Q.top().s ;
        Q.pop() ;
        if( usd[pos] )
            continue ;
        usd[pos] = 1 ;
        res ++ ;
        for( int i=pos-1; i>=0 && arr[i]>=arr[i+1] && !usd[i]; i-- ) {
            usd[i] = 1 ;
            res ++ ;
        }
        for( int i=pos+1;  i<N && arr[i]>=arr[i-1] && !usd[i]; i++ ) {
            usd[i] = 1 ;
            res ++ ;
        }
    }

    res2 = 0 ;
    for( int i=0; i<N; i++ ) {
        if( mapa[i]=='.' )
            Q.push( par(-arr[i],i) ) ;
    }
    while( !Q.empty() ) {
        int pos = Q.top().s ;
        Q.pop() ;
        if( usd[pos] )
            continue ;
        int i ;
        usd[pos] = 1 ;
        for( i=pos-1; i>=0 && arr[i]>=arr[i+1] && !usd[i]; i-- )
            usd[i] = 1 ;
        res2 = max( abs(i-pos), res2 ) ;
        for( i=pos+1;  i<N && arr[i]>=arr[i-1] && !usd[i]; i++ )
            usd[i] = 1 ;
        res2 = max( abs(i-pos), res2 ) ;
    }

    //printf("%d\n", res ) ;

    printf("%d\n", res+res2 ) ;


    return 0 ;
}
