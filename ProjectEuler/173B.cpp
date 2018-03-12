#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std ;
#define lim 1005

int N, M ;
char S[lim][lim] ;
int usdVert[lim], usdHor[lim] ;
queue <int> Q ;

int main() {
    int res = -1 ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ )
        scanf("%s", S[i] ) ;

    Q.push(N) ;
    usdHor[N-1] = 1 ;
    while( !Q.empty() ) {
        int pos = Q.front() ;
        Q.pop() ;
        if( pos<0 ) {
            pos = pos*(-1) -1 ;
            for( int i=0; i<N; i++ ) {
                if( !usdHor[i] && S[i][pos]=='#' ) {
                    usdHor[i] = usdVert[pos]+1 ;
                    Q.push(i+1) ;
                }
            }
        }
        else {
            pos -- ;
            for( int j=0; j<M; j++ ) {
                if( !usdVert[j] && S[pos][j]=='#' ) {
                    usdVert[j] = usdHor[pos]+1 ;
                    Q.push(-j-1) ;
                }
            }
        }
    }

    printf("%d\n", usdHor[0]-1 ) ;

    return 0 ;
}
