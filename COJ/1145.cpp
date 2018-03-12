#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 1005

int N ;
char S[lim][lim], cpy[lim][lim] ;
char res[lim][lim] ;

void caso() {
    for( int i=0; i<N; i++ )
        scanf("%s", S[i] ) ;
    for( int i=0; i<N; i++ )
        scanf("%s", res[i] ) ;

    for( int w=0; w<4; w++ ) {
        for( int i=0; i<N; i++ )
            for( int j=0; j<N; j++ )
                if( S[i][j]=='O' )
                    printf("%c", res[i][j] ) ;
        for( int i=0; i<N; i++ )
            for( int j=0; j<N; j++ )
                cpy[i][j] = S[N-j-1][i] ;
        for( int i=0; i<N; i++ )
            for( int j=0; j<N; j++ )
                S[i][j] = cpy[i][j] ;
    }
    printf("\n" ) ;
}

int main() {

    for( scanf("%d", &N ); N; scanf("%d", &N ) )
        caso() ;

    return 0 ;
}
