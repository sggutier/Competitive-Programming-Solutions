#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 100005

int N ;
char S[lim] ;
int upC[lim], ucC[lim] ;

int main() {
    int res = (1<<30) ;

    scanf("%s", S ) ;
    N = strlen(S) ;

    for( int i=0; i<N; i++ ) {
        upC[i] = 0 ;
        ucC[N-i-1] = 0 ;
        if( i )
            upC[i] += upC[i-1] ;
        if( S[i]>='A' && S[i]<='Z' )
            upC[i] ++ ;
        if( i )
            ucC[N-i-1] += ucC[N-i] ;
        if( S[N-i-1]>='a' && S[N-i-1]<='z' )
            ucC[N-i-1] ++ ;
    }
    upC[N] = upC[N-1] ;
    ucC[N] = 0 ;

    for( int i=0; i<N; i++ )
        res = min( res, i+1-upC[i] + N-i-1-ucC[i+1] ) ;
    res = min( res, N-ucC[0] ) ;

    printf("%d\n", res ) ;

    return 0 ;
}
