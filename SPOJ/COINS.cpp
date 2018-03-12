#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std ;

map <int,long long> dp ;

long long memo( int pos ) {
    if( dp.find(pos) != dp.end() ) {
        return dp[pos] ;
    }
    return dp[pos] = max( pos+0LL, memo(pos/2) + memo(pos/3) + memo(pos/4) ) ;
}

int main() {
    int N ;

    dp[1] = 1LL ;
    dp[0] = 0LL ;
    dp[2] = 2LL ;
    dp[6] = 6LL ;
    dp[3] = 3LL ;
    dp[4] = 4LL ;
    //dp[13] = 13 ;

    while( scanf("%d", &N ) != EOF ) {
        cout << memo(N) << endl ;
    }

    return 0 ;
}
