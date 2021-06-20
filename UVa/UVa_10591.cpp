#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 100005 ;

map <int, bool> dp ;

int sumaNums( int K ) {
    int res = 0 ;
    while( K ) {
	res += (K%10)*(K%10) ;
	K /= 10 ;
    }
    return res ;
}

bool memo( int pos ) {
    map <int, bool> :: iterator tmp =  dp.find(pos) ;
    if( tmp!=dp.end() )
	return tmp -> p2 ;

    dp[pos] = 0 ;
    return dp[pos] = memo( sumaNums(pos) ) ;
}

int main() {
    int T ;

    dp[1] = 1 ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	int a ;
	scanf("%d", &a ) ;
	printf("Case #%d: %d is %sappy number.\n", i+1, a, memo(a)? "a H":"an Unh" ) ;
    }
    
    return 0 ;
}
