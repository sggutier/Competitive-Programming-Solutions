#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std ;

int main() {
	int A, B ;
	int minA=-(1<<30), minB=(1<<30), minC=(1<<30) ;

	scanf("%d%d", &A, &B ) ;
	for( int i=0; i<A; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		minA = max( minA, tmp ) ;
		minB = min( minB, tmp*2 ) ;
	}
	for( int i=0; i<B; i++  ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		minC = min( minC, tmp ) ;
	}

	minA = max( minA, minB ) ;

	if( minA>=minC ) {
		printf("-1\n" ) ;
		return 0 ;
	}

	printf("%d\n", minA ) ;

	return 0 ;
}

