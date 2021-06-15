#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 100
#define par pair<int,int>
#define f first
#define s second

int N, M ;
int arr[lim][lim] ;
int rep[3] ;

int subseg( int hA, int vA, int hB, int vB ) {
    int res = arr[hB][vB] ;
    if( hA )
        res -= arr[hA-1][vB] ;
    if( vA )
        res -= arr[hB][vA-1] ;
    if( hA && hB )
        res += arr[hA-1][vA-1] ;
    return res ;
}

int main() {
    freopen( "input.txt", "r", stdin ) ;
    freopen( "output.txt", "w", stdout ) ;

    int res = 0 ;
    int comp[3] ;

    scanf("%d%d", &N, &M ) ;
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<M; j++ ) {
            scanf("%d", &arr[i][j] ) ;
            if( i )
                arr[i][j] += arr[i-1][j] ;
            if( j )
                arr[i][j] += arr[i][j-1] ;
            if( i && j )
                arr[i][j] -= arr[i-1][j-1] ;
        }
    }
    for( int i=0; i<3; i++  ) {
        scanf("%d", &rep[i] ) ;
    }
    sort( rep, rep+3 ) ;


    for( int i=1; i<N; i++ ) {
        for( int j=i+1; j<N; j++ ) {
            comp[0] = subseg( 0, 0, i-1, M-1 ) ;
            comp[1] = subseg( i, 0, j-1, M-1 ) ;
            comp[2] = subseg( j, 0, N-1, M-1 ) ;
            do {
                int w ;
                for( w=0; w<3 && rep[w]==comp[w]; w++ ) ;
                if( w==3 ) {
                    res ++ ;
                    break ;
                }
            } while( next_permutation(rep,rep+3)  ) ;
            do {
            }while( next_permutation(rep,rep+3)  ) ;
        }
    }
    for( int i=1; i<M; i++ ) {
        for( int j=i+1; j<M; j++ ) {
            comp[0] = subseg( 0, 0, N-1, i-1 ) ;
            comp[1] = subseg( 0, i, N-1, j-1 ) ;
            comp[2] = subseg( 0, j, N-1, M-1 ) ;
            do {
                int w ;
                for( w=0; w<3 && rep[w]==comp[w]; w++ ) ;
                if( w==3 ) {
                    res ++ ;
                    break ;
                }
            } while( next_permutation(rep,rep+3)  ) ;
            do {
            }while( next_permutation(rep,rep+3)  ) ;
        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
