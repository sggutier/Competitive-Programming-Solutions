#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <utility>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std ;

int main() {
    int N, M ;
    int a, b ;
    int res = 0 ;

    scanf("%d%d", &N, &M ) ;

    for( int a=0; a*a<=N; a++ ) {
        int b = N-a*a ;
        if( a + b*b == M )
            res ++ ;
    }

    printf("%d\n", res ) ;

    return 0 ;
}
