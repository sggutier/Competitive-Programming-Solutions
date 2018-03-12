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

void caso() {
    long long a, b ;
    long long K ;
    long long res = 0LL ;

    scanf("%lld%lld", &a, &b ) ;
    K = b-a ;

    res = K ;

    for( long long i=2LL, sum=3LL; a+1<b; i++, sum+=i ) {
	if( 2*sum - i >= K )
	    res = 2*i-1 ;
	else if( 2*sum >= K )
	    res = 2*i ;
	else
	    continue ;
	break ;
    }

    printf("%lld\n", res ) ;
}

int main() {
    int N ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
	caso() ;
    
    return 0 ;
}
