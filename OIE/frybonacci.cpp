#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define mod 1000000000
#define lim 100005

int main() {
    int res[lim] ;
    res[0] = 1 ;
    res[1] = 1 ;
    for( int i=2; i<lim; i++ ) {
        res[i] = (res[i-1]+res[i-2])%mod ;
    }

    int T ;
    for( scanf("%d", &T); T; T-- ) {
        int W ;
        scanf("%d", &W ) ;
        printf("Universo, Toma %d: %d Philip J. Fry\n",W ,res[W] ) ;
    }

    return 0 ;
}
