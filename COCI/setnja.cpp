#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define limT 205
#define limN 200005

int N ;
int arr[limN][2], tam[limN] ;
int minP[limT][limT], minP2[limT][limT] ;

int main() {
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d%d", &arr[i][0], &arr[i][1] ) ;
        scanf("%d", &tam[i] ) ;
    }

    for( int w=1; w<N; w++ ) {
        for( int i=0; i<=tam[w]; i++ )
            for( int j=0; j<=tam[w]; j++ )
                minP2[i][j] = 0 ;
        for( int i=0; i<=tam[w]; i++ )
            for( int j=0; j<=tam[w]; j++ )
                minP[i][j] = minP[i][j] ;
    }

    return 0 ;
}
