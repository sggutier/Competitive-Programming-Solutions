#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std ;
#define lim 53

struct coor {
    int r, c, b ;
    coor() {
    }
    coor( int x, int y, int z ) {
        r = x ;
        c = y ;
        b = z ;
    }
};

int N, M, W ;
char mapa[lim][lim] ;
int minP[lim][lim][1<<10] ;
int gir[lim][lim] ;
queue <coor> Q[2] ;
int dr[] = { -1, 0, 1, 0 } ;
int dc[] = { 0, 1, 0, -1 } ;

int main() {
    W = 0 ;

    coor pos, pos2 ;
    int p=0, p2=1 ;
    int res = (1<<30) ;
    pos.b = 0 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", mapa[i] ) ;
        for( int j=0; j<M; j++ ) {
            gir[i][j] = -1 ;
            if( mapa[i][j] == 'O' ) {
                gir[i][j] = W++  ;
                for( int d=0; d<4; d++ ) {
                    if( mapa[i+dr[d]][j+dc[d]] == '|' ) {
                        pos.b |= (1<<(W-1)) ;
                    }
                }
            }
            else if( mapa[i][j] == 'S' ) {
                pos.r = i ;
                pos.c = j ;
            }
        }

    }

    minP[pos.r][pos.c][pos.b] = 1 ;
    Q[p].push( pos ) ;
    while( !Q[p].empty()  )  {
        while( !Q[p].empty()  )  {
            pos = Q[p].front() ;
            Q[p].pop() ;

            /*cout << pos.r << " " << pos.c << " " << pos.b << " " ;
            cout << minP[pos.r][pos.c][pos.b] ;
            cout << endl ;
            system( "PAUSE" ) ;*/

            for( int d=0; d<4; d++ ) {
                if( dr[d]+pos.r < 0 || dr[d]+pos.r >=N || dc[d]+pos.c < 0 || dc[d]+pos.c >= M )
                    continue ;

                pos2 = pos ;
                pos2.r += dr[d] ;
                pos2.c += dc[d] ;

                if( mapa[pos2.r][pos2.c] == '#' ||  mapa[pos2.r][pos2.c] == 'O' )
                    continue ;

                int d2, x ;
                for( d2=0; d2<4; d2++ ) {
                    if( dr[d2]+pos2.r < 0 || dr[d2]+pos2.r >=N || dc[d2]+pos2.c < 0 || dc[d2]+pos2.c >= M )
                        continue ;
                    if( gir[pos2.r + dr[d2]][pos2.c + dc[d2]]  !=  -1   ) {
                        x = gir[pos2.r + dr[d2]][pos2.c + dc[d2]] ;
                        x = (1<<x) ;
                        break ;
                    }
                }

                if( d2!=4 ) {
                    if( d2%2    !=   ((pos2.b & x)==0)   )   {
                        if( minP[pos2.r][pos2.c][pos2.b]  )
                            continue ;
                        minP[pos2.r][pos2.c][pos2.b] = minP[pos.r][pos.c][pos.b]  ;
                        Q[p].push( pos2 ) ;
                    }
                    else if( d2%2 != d%2 ) {
                        pos2.b ^= x ;
                        if( minP[pos2.r][pos2.c][pos2.b]  )
                            continue ;
                        minP[pos2.r][pos2.c][pos2.b] = minP[pos.r][pos.c][pos.b] +1 ;
                        Q[p2].push( pos2 ) ;
                    }
                }
                else {
                    if( minP[pos2.r][pos2.c][pos2.b]  )
                        continue ;
                    minP[pos2.r][pos2.c][pos2.b] = minP[pos.r][pos.c][pos.b]  ;
                    Q[p].push( pos2 ) ;
                }

            }
        }

        swap( p, p2 ) ;
    }


    for( int r=0; r<N; r++ ) {
        for( int c=0; c<M; c++ ) {
            if( mapa[r][c] != 'E' )
                continue ;
            for( int b=0; b<(1<<W); b++ ) {
                if( minP[r][c][b] )
                    res = min( res, minP[r][c][b] ) ;
            }
        }
    }

    res %= (1<<30) ;
    cout << res-1 << endl ;

    return 0 ;
}
