#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1000

int N, M ;
int tip[lim][lim] ;
char S[lim][lim] ;
int dr[] = {-1,0,1,0} ;
int dc[] = {0,1,0,-1} ;

void dfs( int r, int c, int w ) {
    tip[r][c] = w ;
    int x, y ;
    for( int d=0; d<4; d++  ) {
        x = r + dr[d] ;
        y = c + dc[d] ;
        if( x<0 || x>=N || y<0 || y>=M )
            continue ;
        if( S[x][y] != '#' ||  tip[x][y]==w )
            continue ;
        dfs( x, y , w ) ;
    }
}

int prueba( int r, int c ) {
    int w = r*lim + c, k=0 ;
    S[r][c] = '.' ;

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            if( S[i][j]=='#' && tip[i][j]!=w ) {
                dfs( i, j, w ) ;
                k ++ ;
            }
        }
    }

    S[r][c] = '#' ;

    if( k==2 )
        return 1 ;
    return (1<<30) ;
}

int main() {
    int res = (1<<30), tot=0 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ )
        scanf("%s", S[i] ) ;

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            if( S[i][j]!='#' )
                continue ;
            tot ++ ;
            int r, c, w=0 ;
            for( int d=0; d<4; d++ ) {
                r = i+dr[d] ;
                c = j+dc[d] ;
                if( r<0 || r>=N || c<0 || c>=M )
                    continue ;
                if( S[r][c] == '#' )
                    w ++ ;
            }
            res = min( res, w ) ;
            res = min( res, prueba(i,j) ) ;
        }
    }

    if( res==(1<<30) || res==tot-1 )
        printf("-1\n" ) ;
    else
        printf("%d\n", res ) ;

    return 0 ;
}
