#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
#define lim 500

int R, C ;
int N, F ;
int arr[lim][lim] ;
int minV[lim], minH[lim] ;

int main() {
    int res = (1<<29) ;

    scanf("%d%d", &R, &C ) ;
    scanf("%d%d", &N, &F ) ;
    for( int i=0; i<N; i++ ) {
        int a, b ;
        scanf("%d%d", &a, &b ) ;
        arr[a][b] ++ ;
    }

    for( int i=1; i<=R; i++ )
        for( int j=1; j<=C; j++ )
            arr[i][j] += arr[i][j-1] ;
    for( int i=0; i<lim; i++ ) {
        minV[i] = (1<<29) ;
        minH[i] = minV[i] ;
    }

    for( int x=C; x; x-- ) {
        for( int y=C, rA=minV[y+1]; y>=x; y-- ) {
            rA = min( rA, minV[y+1] ) ;
            int a=R, b=R, carg=0, rB=rA ;
            while( b ) {
                carg += arr[b][y] - arr[b][x-1] ;
                while( a>b && (carg>F  ||  arr[a][y]-arr[a][x-1]==0)   ) {
                    carg -= arr[a][y] - arr[a][x-1] ;
                    rB = min( rB, minH[a] ) ;
                    a -- ;
                }

                //cout  << b << " " << x << " , " << a << " " << y << " -> " << carg << endl ;
                //getchar() ;

                if( carg==F ) {
                    //cout  << b << " " << x << " , " << a << " " << y << endl ;
                    minV[x] = min( minV[x], (a-b+y-x+2)*2 ) ;
                    minH[b] = min( minH[b], (a-b+y-x+2)*2 ) ;
                    res = min( res, rB +  (a-b+y-x+2)*2  ) ;

                    carg -= arr[a][y] - arr[a][x-1] ;
                    rB = min( rB, minH[a] ) ;
                    a -- ;
                }
                b -- ;
            }
        }
    }

    if( res==(1<<29) )
        printf("NO\n" ) ;
    else
        printf("%d\n", res ) ;

    return 0 ;
}
