#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 1005 ;

int A, B, N ;
int neg[lim], ptv[lim] ;
int dp[lim][lim][2] ;
bool usd[lim][lim][2] ;

int memo( int x, int y, int tip, int pos ) {
	if( x>A || y>B )
		return (1<<30) ;
	if( usd[x][y][tip] )
		return dp[x][y][tip] ;
	usd[x][y][tip] = 1 ;
	return dp[x][y][tip] = min( memo(x,y+1,1,ptv[y]) + abs(ptv[y]-pos)*(N-x-y),  memo(x+1,y,0,neg[x]) + abs(neg[x]-pos)*(N-x-y)  ) ;
}

int main() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		if( tmp<=0 ) 
			neg[A++] = tmp ;
		else
			ptv[B++] = tmp ;
	}

	sort( neg, neg+A ) ;
	reverse( neg, neg+A ) ;
	sort( ptv, ptv+B ) ;
	usd[A][B][0] = usd[A][B][1] = 1 ;

	printf("%d\n", min(  memo(1,0,0,neg[0]) - neg[0]*N,  memo(0,1,1,ptv[0]) + ptv[0]*N )   ) ;

	return 0 ;
}


