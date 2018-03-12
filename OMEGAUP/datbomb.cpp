#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
using namespace std ;
#define par pair<int,int>
#define r first
#define c second
const int lim = 16 ;

int N, M ;
char mapa[lim][lim+4] ;
int minP[lim][lim][lim][lim][lim][lim] ;
queue <par> Q, Q2, Q3 ;
int reg[lim][lim][lim][lim] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

void ff( par prd, par pos, int col ) {
    if( pos==prd || pos.r<0 || pos.r>=N || pos.c<0 || pos.c>=M || reg[prd.r][prd.c][pos.r][pos.c] || mapa[pos.r][pos.c]=='#' )
        return ;
    reg[prd.r][prd.c][pos.r][pos.c] = col ;
    for( int d=0; d<4; d++ )
        ff( prd, par(pos.r+dr[d],pos.c+dc[d]), col ) ;
}

void separa( par prd ) {
    int K = 1 ;
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            if( mapa[i][j]=='#' || reg[prd.r][prd.c][i][j] )
                continue ;
            ff( prd, par(i,j), K ) ;
            K ++ ;
        }
    }
}

int main() {
    par pos, rca, bmb ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", mapa[i] ) ;
        for( int j=0; j<M; j++ ) {
            if( mapa[i][j]=='P' ) {
                mapa[i][j] = '.' ;
                pos = par(i,j) ;
            }
            else if( mapa[i][j]=='B' ) {
                mapa[i][j] = '.' ;
                bmb = par(i,j) ;
            }
            else if( mapa[i][j]=='R' ) {
                mapa[i][j] = '.' ;
                rca= par(i,j) ;
            }
        }
    }

    for( int i=0; i<N; i++ )
        for( int j=0; j<M; j++ )
            separa( par(i,j)  ) ;

    Q.push(pos) ;
    Q2.push(rca) ;
    Q3.push(bmb) ;
    minP[pos.r][pos.c][rca.r][rca.c][bmb.r][bmb.c] = 1 ;
    while( !Q.empty() ) {
        pos = Q.front() ;
        rca = Q2.front() ;
        bmb = Q3.front() ;
        Q.pop() ;
        Q2.pop() ;
        Q3.pop() ;

        if( reg[rca.r][rca.c][pos.r][pos.c] != reg[rca.r][rca.c][bmb.r][bmb.c] ) {
            /*cout << pos.r << " " << pos.c << endl ;
            cout << rca.r << " " << rca.c << endl ;
            cout << bmb.r << " " << bmb.c << endl ;
            for( int i=0; i<N; i++ ) {
                for( int j=0; j<M; j++ )
                    printf("%d ", reg[rca.r][rca.c][i][j] ) ;
                printf("\n" ) ;
            }*/
            printf("%d\n", minP[pos.r][pos.c][rca.r][rca.c][bmb.r][bmb.c] -1 ) ;
            return 0 ;
        }

        for( int d=0; d<4; d++ ) {
            par x=pos, y=rca, z=bmb ;
            x.r += dr[d] ;
            x.c += dc[d] ;
            if( x==y ) {
                y.r += dr[d] ;
                y.c += dc[d] ;
            }
            else if( x==z ) {
                z.r += dr[d] ;
                z.c += dc[d] ;
            }

            if( y==z )
                continue ;
            if( x.r<0 || x.r>=N || x.c<0 || x.c>=M )
                continue ;
            if( y.r<0 || y.r>=N || y.c<0 || y.c>=M )
                continue ;
            if( z.r<0 || z.r>=N || z.c<0 || z.c>=M )
                continue ;
            if( mapa[x.r][x.c]=='#' || mapa[y.r][y.c]=='#' || mapa[z.r][z.c]=='#' )
                continue ;

            if( minP[x.r][x.c][y.r][y.c][z.r][z.c] )
                continue ;

            minP[x.r][x.c][y.r][y.c][z.r][z.c] = minP[pos.r][pos.c][rca.r][rca.c][bmb.r][bmb.c] +1 ;
            Q.push(x) ;
            Q2.push(y) ;
            Q3.push(z) ;
        }
    }

    printf("-1\n" ) ;

    return 0 ;
}
