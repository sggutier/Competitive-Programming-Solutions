#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
#define lim 10

int main() {
    int r = 0 ;
    int res = 0 ;
    int marcA[lim], marcB[lim] ;

    for( int i=0; i<(1<<lim); i++ ) {
        int a = 0 ;
        memset( marcA, 0, sizeof(marcA) ) ;
        for( int j=0; j<lim; j++ ) {
            if( (1<<j) & i ) {
                marcA[j] = 1 ;
                if( j==6 )
                    marcA[9] = 1 ;
                if( j==9 )
                    marcA[6] = 1 ;
                a ++ ;
            }
        }
        if( a!=6 )
            continue ;
        for( int k=i; k<(1<<lim); k++ ) {
            a = 0 ;
            memset( marcB, 0, sizeof(marcB) ) ;
            for( int j=0; j<lim; j++ ) {
                if( (1<<j) & k ) {
                    marcB[j] = 1 ;
                    if( j==6 )
                        marcB[9] = 1 ;
                    if( j==9 )
                        marcB[6] = 1 ;
                    a ++ ;
                }
            }
            if( a!=6 )
                continue ;

            for( a=1; a<lim; a++ ) {
                r = 0 ;
                for( int x=0; x<lim && !r; x++ ) {
                    if( marcA[x] == 0 )
                        continue ;
                    for( int y=0; y<lim && !r; y++ ) {
                        if( marcB[y] == 0 )
                            continue ;
                        if( x*10 + y == a*a  ) {
                            r = 1 ;
                        }
                        else if( y*10 + x == a*a  ) {
                            r = 1 ;
                        }
                    }
                }
                if( !r )
                    break ;
            }

            if( a==10 ) {
                res ++ ;
                /*for( int j=0; j<lim; j++ )
                    if( (1<<j) & i )
                        printf("%d ", j ) ;
                printf("\n" ) ;
                for( int j=0; j<lim; j++ )
                    if( (1<<j) & k )
                        printf("%d ", j ) ;
                printf("\n" ) ;
                printf("-----------\n" ) ;
                getchar() ;*/
            }


        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
