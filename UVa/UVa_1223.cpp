#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 100005

int N ;
char S[lim] ;

bool taut() {
    char W ;

    N = strlen(S) ;

    if( S[0]>='A' && S[0]<='Z' )
        S[0] = S[0]-'A'+'a' ;
    W = S[0] ;

    for( int i=1; i<N; i++ ) {
        if( S[i]==' ' && i+1<N ) {
            if( S[i+1]>='A' && S[i+1]<='Z' )
                S[i+1] = S[i+1]-'A'+'a' ;
            if( S[i+1] != W ) {
                return 0 ;
            }
        }
    }

    return 1 ;
}

int main() {
    gets(S) ;
    while( S[0]!='*' ) {
        if( taut() )
            printf("Y\n" ) ;
        else
            printf("N\n" ) ;
        gets(S) ;
    }
    return 0 ;
}
