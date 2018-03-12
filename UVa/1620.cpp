#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 100005
#define lim2 1005

int nS, nW ;
char S[lim], W[lim] ;
int reg[lim2] ;

bool kmp() {
    scanf("%s", W ) ;
    nW = strlen(W) ;

    reg[0] = -1 ;
    reg[1] = 0 ;
    for( int i=2, ult=0; i<nW; i++ ) {
        if( W[ult]==W[i-1] ) {
            reg[i] = ++ult ;
        }
        else if( ult ) {
            ult = reg[ult] ;
            i -- ;
        }
        else {
            reg[i] = 0 ;
        }
    }

    /*for( int i=0; i<nW; i++ )
        printf("%d ", reg[i] ) ;
    printf("\n" ) ;*/

    for( int i=0, m=0; m+i<nS; i++ ) {
        if( S[m+i]==W[i] ) {
            if( i==nW-1 ) {
                return 1 ;
            }
        }
        else {
            m = m+i-reg[i] ;
            i = max( -1, reg[i]-1 ) ;
        }
    }

    return 0 ;
}

void caso() {
    int T ;

    scanf("%s", S ) ;
    nS = strlen(S) ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
        if( kmp() )
            printf("y\n" ) ;
        else
            printf("n\n" ) ;
    }
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
        caso() ;

    return 0 ;
}

