#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int N ;
    char S[2000] ;
    int i ;

    scanf("%d", &N ) ;
    scanf("%s", S ) ;

    sort( S, S+N ) ;
    sort( S+N, S+N*2 ) ;

    for( i=0; i<N; i++ )
        if( S[i]>=S[i+N] )
            break ;
    if( i==N ) {
        printf("YES\n" ) ;
        return 0 ;
    }

    for( i=0; i<N; i++ )
        if( S[i]<=S[i+N] )
            break ;
    if( i==N ) {
        printf("YES\n" ) ;
        return 0 ;
    }


    printf("NO\n" ) ;

    return 0 ;
}
