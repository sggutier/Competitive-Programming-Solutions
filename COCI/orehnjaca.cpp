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
#include <stack>
using namespace std ;
const int lim = 1005 ;

bool usd[lim] ;

int main() {
	int N, E ;
	int pA, rA = -(1<<30), pB, rB=rA ;
	int ult = 0 ;

	scanf("%d%d", &N, &E ) ;
	for( int i=0; i<E; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		if( b-a+1>rA ) {
			rA = b-a+1 ;
			pA = i ;
		}
		int c = 0 ;
		for( int j=a; j<=b; j++ ) {
			if( usd[j] )
				continue ;
			usd[j] = 1 ;
			c ++ ;
		}
		if( c>rB ) {
			rB = c ;
			pB = i ;
		}
	}

	printf("%d\n%d\n", pA+1, pB+1 ) ;

	return 0 ;
}

