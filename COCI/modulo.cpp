#include <cstdio>
#include <algorithm>
#include <cstdio>
using namespace std ;

bool usd[50] ;

int main() {
    int N ;
    int res = 0 ;

    N = 10 ;
    for(int i=0; i<N; i++ ) {
        int a ;
        scanf("%d", &a ) ;
        a %= 42 ;
        if( usd[a] )
            continue ;
        usd[a] = 1 ;
        res ++ ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
