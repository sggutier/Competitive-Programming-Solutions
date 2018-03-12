#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <stack>
#include <map>
#include <utility>
#include <cmath>
using namespace std ;

int main() {
    freopen( "regions.in", "r", stdin ) ;
    //freopen( "regions.out", "w", stdout ) ;
    int N, R, Q ;
    int a, b, c ;
    scanf("%d%d%d", &N, &R, &Q ) ;
    scanf("%d", &a ) ;
    for( int i=1; i<N; i++ ) {
        scanf("%d%d", &a, &b ) ;
    }
    for( int i=0; i<Q; i++ ) {
        scanf("%d%d", &a, &b ) ;
        printf("0\n" ) ;
    }

    return 0 ;
}
