#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
using namespace std ;
#define par pair<int,int>
#define r first
#define c second
const int lim = 45 ;

int N ;
char arr[lim][lim] ;
queue <par> Q, Q2 ;
int minP[lim][lim][lim][lim] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

void pucha( par &W, par K, int d ) {
    if( arr[W.r-dr[d]][W.c-dc[d]] != '.' || par( W.r - dr[d], W.c - dc[d] )==K  )
        return ;
    while( arr[W.r][W.c]!='A' && arr[W.r + dr[d]][W.c + dc[d]]!='#' && par( W.r + dr[d], W.c + dc[d] )!=K  ) {
        W.r += dr[d] ;
        W.c += dc[d] ;
    }
}

int main() {
    par A, B, X, Y ;
    int w = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", arr[i] ) ;
        for( int j=0; j<N; j++ ) {
            if( arr[i][j] == 'B' ) {
                if( w )
                    B = par( i, j ) ;
                else
                    A = par( i, j ) ;
                arr[i][j] = '.' ;
                w = 1 ;
            }
        }
    }

    minP[A.r][A.c][B.r][B.c] = 1 ;
    Q.push( A ) ;
    Q2.push( B ) ;
    while( !Q.empty() ) {
        A = Q.front() ;
        B = Q2.front() ;
        Q.pop() ;
        Q2.pop() ;

        if( arr[A.r][A.c]=='A' || arr[B.r][B.c]=='A' ) {
            printf("%d\n", minP[A.r][A.c][B.r][B.c]-1 ) ;
            break ;
        }

        for( int d=0; d<4; d++ ) {
            X = A ;
            Y = B ;
            pucha( X, Y, d ) ;
            if( minP[X.r][X.c][Y.r][Y.c]==0 ) {
                Q.push(X) ;
                Q2.push(Y) ;
                minP[X.r][X.c][Y.r][Y.c] = minP[A.r][A.c][B.r][B.c]+1 ;
            }
            X = A ;
            Y = B ;
            pucha( Y, X, d ) ;
            if( minP[X.r][X.c][Y.r][Y.c]==0 ) {
                Q.push(X) ;
                Q2.push(Y) ;
                minP[X.r][X.c][Y.r][Y.c] = minP[A.r][A.c][B.r][B.c]+1 ;
            }
        }
    }

    return 0 ;
}
