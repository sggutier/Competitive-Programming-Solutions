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
const int lim = 314160 ;

int N, Q ;
int ren[lim], col[lim] ;
char S[15] ;

int main() {
	int rA=0, rB=0 ;
	int a, b ;

	scanf("%d%d", &N, &Q ) ;
	for( int i=0; i<Q; i++ ) {
		scanf("%s", S ) ;
		scanf("%d%d", &a, &b ) ;
		if( S[0]=='R' )
			ren[a-1] += b ;
		else
			col[a-1] += b ;
	}

	for( int i=0; i<N; i++ ) {
		rA = max( rA, ren[i] ) ;
		rB = max( rB, col[i] ) ;
	}

	printf("%d\n", rA+rB ) ;

	return 0 ;
}


