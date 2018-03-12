#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 1000006

int rep[lim] ;
char S[lim] ;

int main() {
    int K, N ;
    long long res = 0LL ;

    rep[0] = 1 ;
    scanf("%d", &K ) ;
    scanf("%s", S ) ;
    for( int i=0, carg=0; S[i]; i++ ) {
        carg += S[i]-'0' ;
        if( carg>=K )
            res += rep[ carg-K ] ;
        rep[carg] ++ ;
    }

    cout << res << endl ;

    return 0 ;
}
