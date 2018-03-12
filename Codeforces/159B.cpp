#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std ;
#define lim 1005
#define par pair<int,int>
#define f first
#define s second

int P, M ;
int penc[lim][lim], rec[lim][lim] ;

int main() {
    int resB=0, resC=0 ;

    scanf("%d%d", &P, &M ) ;
    for( int i=0; i<P; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        penc[b][a] ++ ;
    }
    for( int i=0; i<M; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        rec[b][a] ++ ;
    }

    for( int i=0; i<lim; i++ ) {
        int a=0, b=0 ;
        for( int j=0; j<lim; j++ ) {
            resB += min( penc[i][j], rec[i][j] ) ;
            a += penc[i][j] ;
            b += rec[i][j] ;
        }
        resC += min( a, b ) ;
    }

    printf("%d %d\n", resC, resB ) ;

    return 0 ;
}
