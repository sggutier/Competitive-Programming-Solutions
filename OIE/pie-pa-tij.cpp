#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std ;

map <string,int> M ;

int main() {
    int res[] = {0,0} ;
    char S[1000], W[1000] ;
    int a, b ;

    M["piedra"] = 0 ;
    M["papel"] = 1 ;
    M["tijeras"] = 2 ;

    while( scanf("%s%s", S, W ) != EOF  )  {
        a = M[S] ;
        b = M[W] ;
        if( a==(b+1)%3 )
            res[0] += 2 ;
        else if( b==(a+1)%3 )
            res[1] += 2 ;
        else {
            res[0] ++ ;
            res[1] ++ ;
        }
    }

    printf("%d %d\n", res[0], res[1] ) ;

    return 0 ;
}
