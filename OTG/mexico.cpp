#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1003

int N, W ;
bool adj[lim][lim] ;
int ant[lim][lim][2] ;

int main() {
    int rA, rB, rC ;

    scanf("%d%d", &N, &W ) ;
    for( int i=0; i<W; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        a--, b-- ;
        adj[a][b] = 1 ;
        adj[b][a] = 1 ;
    }

    for( int i=0; i<N; i++ ) {
        ant[i][i][0] = 1 ;
        ant[i][i][1] = 1 ;
    }
    for( int i=0; i<N; i++ ) {
        int a=i, b=(i+1)%N ;
        if( adj[a][b] ) {
            ant[a][b][1] = a*1000 + a +1 ;
            ant[a][b][0] = b*1000 + b +1 ;
        }
    }

    for( int tam=2; tam<N; tam++ ) {
        for( int i=0; i<N; i++ ) {
            int A, B, x, y ;
            A = i ;
            B = (A+tam)%N ;
            x = (A+1)%N ;
            y = (A+tam-1)%N ;

            if( ant[A][y][1] && adj[y][B] ) {
                ant[A][B][1] = 1*1000000 + A*1000 + y + 1 ;
            }
            else if( ant[A][y][0] && adj[A][B] ) {
                ant[A][B][1] = 0*1000000 + A*1000 + y + 1 ;
            }

            if( ant[x][B][0] && adj[x][A] ) {
                ant[A][B][0] = 0*1000000 + x*1000 + B + 1 ;
            }
            else if( ant[x][B][1] && adj[B][A] ) {
                ant[A][B][0] = 1*1000000 + x*1000 + B + 1 ;
            }
        }
    }

    /*for( int tam=1; tam<N; tam++ ) {
        for( int i=0; i<N; i++ ) {
            int A, B, x, y ;
            A = i ;
            B = (A+tam)%N ;
            x = (A+1)%N ;
            y = (A+tam-1)%N ;

            if( ant[A][B][0] )
                printf("%d %d [0] -> %d %d %d\n", A+1, B+1, (  (ant[A][B][0] -1)/1000 )%1000+1,  (ant[A][B][0] -1)%1000+1, (ant[A][B][0] -1)/1000000 ) ;
            if( ant[A][B][1] )
                printf("%d %d [1] -> %d %d %d\n", A+1, B+1, (  (ant[A][B][1] -1)/1000 )%1000+1,  (ant[A][B][1] -1)%1000+1, (ant[A][B][1] -1)/1000000 ) ;
        }
        //printf("\n" ) ;
    }*/

    for( rA=0, rB=N-1; rA<N && ant[rA][rB][0]==0 && ant[rA][rB][1]==0; rA++, rB=(rB+1)%N ) ;
    if( rA==N ) {
        printf("-1\n" ) ;
        return 0 ;
    }

    if( ant[rA][rB][0] )
        rC = 0 ;
    else
        rC = 1 ;

    while( rA!=rB ) {
        int tmp ;
        if( !rC )
            printf("%d\n", rA+1 ) ;
        else
            printf("%d\n", rB+1 ) ;
        //cout << rA+1 << " " << rB+1 << " " << rC << endl ;
        tmp = ant[rA][rB][rC] -1 ;
        rA = (tmp/1000) % 1000 ;
        rB = tmp % 1000 ;
        rC = tmp/1000000 ;
    }
    printf("%d\n", rA+1 ) ;
    //cout << -1 << endl ;

    return 0 ;
}

