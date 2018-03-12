#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second

int main() {
    int N ;
    par arr[1005];

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        arr[i].s = i ;
        scanf("%d", &arr[i].f ) ;
    }

    sort( arr, arr+N ) ;

    printf("%d\n",

    return 0 ;
}
