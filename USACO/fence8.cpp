/*
ID: chencho2
LANG: C++
TASK: fence8
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 1500

int N, M ;
int opc[lim], arr[lim] ;

int main() {
    //freopen( "fence8.in" , "r", stdin  ) ;
    //freopen( "fence8.out", "w", stdout ) ;

    int res = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &opc[i] ) ;
    scanf("%d", &M ) ;
    for( int i=0; i<M; i++ )
        scanf("%d", &arr[i] ) ;

    sort( opc, opc+N ) ;
    sort( arr, arr+M ) ;
    for( int i=0, j=0; i<M && j<N; i++, res++ ) {

        for( ; j<N && arr[j]<arr2[i]; j++ ) ;
        if( j>=N ) {
            break ;
        }

        printf("%d %d\n", arr[j], arr2[i] ) ;

        arr[j] -= arr2[i] ;

    }


    printf("%d\n", res ) ;

    return 0 ;
}
