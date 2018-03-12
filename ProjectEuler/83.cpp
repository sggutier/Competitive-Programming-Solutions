#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define lim 1005
#define f first
#define s second

int N, M ;
int arr[lim][lim], dp[lim][lim] ;
bool usd[lim][lim] ;
int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1} ;

int main() {
    freopen( "matrix.txt", "r", stdin ) ;

    priority_queue <par> Q ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ )
        for( int j=0; j<M; j++ )
            scanf("%d", &arr[i][j] ) ;

    Q.push( par(0,0) ) ;
    while( !Q.empty() ) {
        par pos = Q.top() ;
        int r=pos.s/M, c=pos.s%M, w=-pos.f+arr[r][c] ;
        Q.pop() ;
        if( usd[r][c] )
            continue ;
        //printf("%d %d -> %d\n", r, c, w ) ;
        dp[r][c] = w ;
        usd[r][c] = 1 ;
        for( int d=0; d<4; d++ ) {
            int i=r+dr[d], j=c+dc[d] ;
            if( i>=0 && i<N && j>=0 && j<M ) {
                Q.push( par(-w,i*M+j)  ) ;
            }
        }
    }

    printf("%d\n", dp[N-1][M-1] ) ;

    return 0 ;
}
