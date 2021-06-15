#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int N, M ;
int arr[100][100] ;
int col[100], fil[100] ;

int main() {
    int res = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        for( int j=0; j<N; j++ ) {
            scanf("%d", &arr[i][j] ) ;
            fil[i] += arr[i][j] ;
            col[j] += arr[i][j] ;
        }
    }

    for( int i=0; i<N; i++ ) {
        for( int j=0; j<N; j++ ) {
            if( col[j]>fil[i] )
                res ++ ;
        }
    }

    printf("%d\n", res ) ;

    return 0 ;
}
