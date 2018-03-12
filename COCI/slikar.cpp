#include <queue>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
    int N, M ;
    char arr[100][100] ;
    queue <int> qA[2], qB[2] ;
    int dr[] = { -1, 0, 1, 0 } ;
    int dc[] = { 0, 1, 0, -1 } ;
    int act=0, sig=1 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%s", arr[i] ) ;
        for( int j=0; j<M; j++ ) {
            if( arr[i][j]=='S' )
                qA[act].push( i*M + j ) ;
            if( arr[i][j]=='*' )
                qB[act].push( i*M + j ) ;
        }
    }

    for( int res=0; !qA[act].empty(); res++, swap(act,sig)   ) {

        while( !qA[act].empty() ) {
            int r=qA[act].front()/M, c=qA[act].front()%M ;
            qA[act].pop() ;
            if( arr[r][c]=='*' )
                continue ;
            for( int d=0, x, y; d<4; d++ ) {
                x = dr[d] + r ;
                y = dc[d] + c ;
                if( x<0 || x>=N || y<0 || y>=M  )
                    continue ;
                if( arr[x][y]=='S' || arr[x][y]=='*' || arr[x][y]=='X' )
                    continue ;
                if( arr[x][y]=='D' ) {
                    printf("%d\n", res+1 ) ;
                    return 0 ;
                }
                arr[x][y] = 'S' ;
                qA[sig].push( x*M + y ) ;
            }
        }

        while( !qB[act].empty() ) {
            int r=qB[act].front()/M, c=qB[act].front()%M ;
            qB[act].pop() ;
            for( int d=0, x, y; d<4; d++ ) {
                x = dr[d] + r ;
                y = dc[d] + c ;
                if( x<0 || x>=N || y<0 || y>=M  )
                    continue ;
                if( arr[x][y]=='D' || arr[x][y]=='*' || arr[x][y]=='X' )
                    continue ;
                arr[x][y] = '*' ;
                qB[sig].push( x*M + y ) ;
            }
        }

    }

    printf("KAKTUS\n" ) ;

    return 0 ;
}
