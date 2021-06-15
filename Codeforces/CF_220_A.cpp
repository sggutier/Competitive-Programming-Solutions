#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define lim 100005

int main() {
    int N ;
    par arr[lim] ;
    int res = 0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        arr[i].s = i ;
        scanf("%d", &arr[i].f ) ;
    }

    sort( arr, arr+N ) ;
    for( int i=0; i<N; ) {
        int j ;
        for( j=i; j<N && arr[j].f==arr[i].f; j++ ) ;
        for( int k=i; k<N && arr[k].f==arr[i].f; k++ )
            if( arr[k].s<i || arr[k].s>=j )
                res ++ ;
        i = j ;
    }

    cout << ( res<=2 ? "YES" : "NO" ) << endl ;

    return 0 ;
}
