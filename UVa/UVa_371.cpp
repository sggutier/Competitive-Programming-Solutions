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
using namespace std ;
const int lim = 100005 ;

map <long long, int> dp ;

int memo( long long pos ) {
    map <long long, int> :: iterator it = dp.find(pos) ;
    if( it!=dp.end()  )  {
	return it -> second ;
    }
    dp[pos] = memo( pos%2==0? pos/2 : 3*pos+1 ) +1 ;
    // cout << pos << endl ;
    return dp[pos] ;
}

int main() {
    long long a, b ;

    dp[1] = 0 ;

    while( scanf("%lld%lld", &a, &b) != EOF
	   and ( a or b ) ) {
	if( a>b )
	    swap( a, b ) ;
	int res=-1 ;
	long long pos = a ;
	for( long long i=a; i<=b; i++ ) {
	    int tmp = memo( i ) ;
	    if( i==1 )
		tmp = 3 ;
	    if( tmp > res ) {
		res = tmp ;
		pos = i ;
	    }
	}
	printf("Between %lld and %lld, %lld generates the longest sequence of %d values.\n", a, b, pos, res ) ;
    }
    
    return 0 ;
}
