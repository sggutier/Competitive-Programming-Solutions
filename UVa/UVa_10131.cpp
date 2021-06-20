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
#define par pair<int,int>
#define p1 first
#define p2 second

int main() {
    int N ;
    int dp[lim], ant[lim] ;
    int res = 0 ;
    pair< par, int > eleph[lim] ;

    while( scanf("%d%d", &eleph[N].p1.p1, &eleph[N].p1.p2 ) != EOF ) {
	eleph[N].p1.p2 *= -1 ;
	eleph[N].p2 = N ;
	N ++ ;
    }

    sort( eleph, eleph+N ) ;
    reverse( eleph, eleph+N ) ;
    for( int i=0; i<N; i++ ) {
	dp[i] = 0 ;
	ant[i] = -1 ;
	for( int j=0; j<i; j++ ) {
	    if( eleph[i].p1.p1 < eleph[j].p1.p1
		and eleph[i].p1.p2 < eleph[j].p1.p2
		and dp[j] > dp[i] ) {
		dp[i] = dp[j] ;
		ant[i] = j ;
	    }
	}
	res = max( res, dp[i]+1 ) ;
	dp[i] ++ ;
    }

    printf("%d\n", res ) ;
    for( int i=0; i<N; i++ ) {
	if( dp[i]!=res )
	    continue ;
	for( int j=i; j!=-1; j=ant[j] ) {
	    printf("%d\n", eleph[j].p2 +1 ) ;
	}
	break ;
    }
    
    return 0 ;
}
