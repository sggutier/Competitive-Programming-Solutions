#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 100005 ;

map < int, int > rep ;

int main() {
	freopen( "lineup.in", "r", stdin ) ;
	freopen( "lineup.out", "w", stdout ) ;

	int N, K ;
	int res = 0, w=0 ;
	int arr[lim] ;

	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		rep[ arr[i] ] = 0 ;
	}

	for( int i=0, j=0; i<N; i++ ) {
		if( rep[ arr[i] ] == 0  )
			w ++ ;
		rep[ arr[i] ] ++ ;
		while( w-1>K ) {
			rep[ arr[j] ] -- ;
			if( rep[ arr[j] ] == 0  )
				w -- ;
			j ++ ;
		}
		res = max( res, rep[ arr[i] ] ) ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}


