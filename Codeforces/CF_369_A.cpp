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

int main() {
	int N, M, K ;
	int cntA=0, cntB=0 ;
	int res = 0 ;

	scanf("%d%d%d", &N, &M, &K ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		if( tmp==1 ) 
			cntA ++ ;
		else
			cntB ++ ;
	}

	res += max( 0, cntA-M ) ;
	M = max( 0, M-cntA ) ;
	res += max( 0, cntB-M-K ) ;

	printf("%d\n", res ) ;

	return 0 ;
}


