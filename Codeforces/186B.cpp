#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;
#define par pair<int,int>
#define f first
#define s second
#define lim 1005

int main() {
    int N, a, b, k ;
    par arr[lim] ;

    scanf("%d%d%d%d", &N, &a, &b, &k ) ;
    k = 100-k ;
    for( int i=0; i<N; i++ ) {
        int x, y ;
        scanf("%d%d", &x, &y ) ;
        arr[i].s = i+1 ;
        arr[i].f = -max( x*a*k + y*b*100, y*a*k + x*b*100 ) ;
    }

    sort( arr, arr+N ) ;
    for( int i=0; i<N; i++ ) {
        printf("%d %d.%d%d\n", arr[i].s, -arr[i].f/100, -(arr[i].f%100)/10, -arr[i].f%10 ) ;
    }

    return 0 ;
}
