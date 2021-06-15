#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 100005
#define par pair<int,int>
#define f first
#define s second

int main() {
    int N ;
    par arr[lim] ;
    int R[2] = {0,0} ;
    int res[lim][2] ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &arr[i].f ) ;
        arr[i].s = i ;
    }

    sort( arr, arr+N ) ;
    for( int i=0; i<N; i++ ) {
        res[ R[i%2]++ ][i%2] = arr[i].s ;
    }

    for( int k=0; k<2; k++ ) {
        printf("%d\n", R[k] ) ;
        for( int i=0; i<R[k]; i++ ) {
            printf("%d ", res[i][k]+1 ) ;
        }
        printf("\n" ) ;
    }

    return 0 ;
}
