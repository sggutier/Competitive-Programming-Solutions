#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1005

int N, M ;
char S[lim][lim] ;
int tipo[lim][lim], marc[lim][lim] ;
int W, K, T ;
int dr[] = {-1,-1, 0,-1, 1,1, 0,1} ;
int dc[] = {0,-1, 1,1, 0,1, -1,-1} ;
int P ;
int pilX[lim*lim], pilY[lim*lim] ;
int carg[lim][lim] ;

void dfs( int r, int c ) {
    if( r<0 || r>=N || c<0 || c>=M || tipo[r][c]!=-1 || S[r][c]!=W ) {
        return ;
    }
    tipo[r][c] = T ;
    for( int i=0; i<8; i+=2 ) {
        dfs( dr[i]+r, dc[i]+c ) ;
    }
}

void lim0( int r, int c ) {
    if( r<0 || r>=N || c<0 || c>=M || S[r][c]=='1' || marc[r][c]!=-1 ) {
        return ;
    }
    //printf("%d %d\n", r, c ) ;
    marc[r][c] = T ;
    int i, j, x, y ;
    for( int d=0; d<8; d++ ) {
        i=r+dr[d], j=c+dc[d] ;
        if( i<0 || i>=N || j<0 || j>=M ) {
            W = -(1<<30) ;
        }
        else if( S[i][j]=='1' && marc[i][j]!=T ) {
            if( tipo[i][j]!=K )
                W = -(1<<30) ;
            W ++ ;
            marc[i][j] = T ;

            pilX[P] = i ;
            pilY[P] = j ;
            P ++ ;
            for( int R=0; R<8; R+=2 ) {
                x = i+dr[R], y=j+dc[R] ;
                if( x>=0 && x<N && y>=0 && y<M && S[x][y]=='1' ) {
                    carg[x][y] ++ ;
                }
            }
        }
    }
    for( int d=0; d<8; d++ ) {
        lim0( r+dr[d], c+dc[d] ) ;
    }
}

bool checa() {
    bool res = 1 ;
    int i, j, x, y ;
    for( int a=0; a<P; a++ ) {
        i = pilX[a], j=pilY[a] ;
        if( carg[i][j]!=2 )
            res = 0 ;
    }
    for( int a=0; a<P; a++ ) {
        i = pilX[a], j=pilY[a] ;
        for( int R=0; R<8; R+=2 ) {
            x = i+dr[R], y=j+dc[R] ;
            if( x>=0 && x<N && y>=0 && y<M && S[x][y]=='1' ) {
                carg[x][y] -- ;
            }
        }
    }
    P = 0 ;
    return res ;
}

int main() {
    int res = 0 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", S[i] ) ;
        for( int j=0; j<M; j++) {
            tipo[i][j] = -1 ;
            marc[i][j] = -1 ;
        }
    }

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            T = i*M + j ;
            W = S[i][j] ;
            if( tipo[i][j] == -1 )
                dfs( i, j ) ;
        }
    }

    for( int i=0; i<N; i++ ) {
        int ult = -1 ;
        for( int j=0; j<M; j++ ) {
            if( S[i][j] == '1'  ) {
                ult = tipo[i][j] ;
            }
            else if( marc[i][j]==-1 ) {
                K = ult ;
                W = 0 ;
                T = tipo[i][j] ;
                P = 0 ;
                lim0( i, j ) ;
                //printf("-----\n" ) ;
                if( checa() )
                    res = max( res, W ) ;
            }
        }
    }

    for( int i=0; i+1<N; i++ )
        for( int j=0; j+1<M; j++ )
            if( S[i][j]=='1' && S[i][j+1]=='1' && S[i+1][j]=='1' && S[i+1][j+1]=='1' )
                res = max( res, 4 ) ;

    printf("%d\n", res ) ;

    return 0 ;
}
