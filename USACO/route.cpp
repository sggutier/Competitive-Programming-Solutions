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
const int lim = 40005 ;

int T[2], E ;
list <int> adj[lim][2] ;
int dp[lim][2], dp[lim][2] ;

int main() {
	int res = -(1<<30) ;

	scanf("%d%d", &T[0], &T[1] ) ;
	for( int k=0; k<2; k++ )
		for( int i=0; i<T[k]; i++ )
			scanf("%d", &arr[i][k] ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		if( a<b ) 
	}

	return 0 ;
}


