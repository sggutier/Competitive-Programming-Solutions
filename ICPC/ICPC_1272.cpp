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
const int lim = 1005 ;

int res[lim] ;

void caso() {
	int N, C ;

	memset( res, 0, sizeof(res) ) ;

	scanf("%d%d", &N, &C ) ;
	for( int i=0; i<N; i++ ) {
		int x, y ;
		scanf("%d%d", &x, &y ) ;
		for( int j=C; j>=x; j-- ) 
			res[j] = max( res[j], res[j-x] +y ) ;
	}

	printf("%d\n", res[C] ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) 
		caso() ;

	return 0 ;
}


