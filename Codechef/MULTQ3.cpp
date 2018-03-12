#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 100005 ;

int res ;
int segT[lim*3][3], flg[lim*3] ;

void act( int pos, int A, int B, int le, int ro ) {
	if( le<=A && ro>=B ) {
		int tmp = segT[pos][2] ;
		segT[pos][2] = segT[pos][1] ;
		segT[pos][1] = segT[pos][0] ;
		segT[pos][0] = tmp ;
		flg[pos] ++ ;
	}
	else {
		int piv = (A+B)/2 ;

		segT[pos][0] = 0 ;
		segT[pos][1] = 0 ;
		segT[pos][2] = 0 ;

		if( A<=ro && piv>=le && A<=piv ) {
			act( pos*2, A, piv, le, ro ) ;
			segT[pos][0] += segT[pos*2][0] ;
			segT[pos][1] += segT[pos*2][1] ;
			segT[pos][2] += segT[pos*2][2] ;
		}

		piv ++ ;
		if( piv<=ro && B>=le && piv<=B ) {
			act( pos*2+1, piv, B, le, ro ) ;
			segT[pos][0] += segT[pos*2+1][0] ;
			segT[pos][1] += segT[pos*2+1][1] ;
			segT[pos][2] += segT[pos*2+1][2] ;
		}
	}
}

void qry( int pos, int A, int B, int le, int ro, int F ) {
	if( A>ro || B<le || A>B )
		return ;
	else if( le<=A && ro>=B ) {
		res += segT[pos][F%3] ;
	}
	else {
		int piv = (A+B)/2 ;

		F += flg[pos] ;

		qry( pos*2, A, piv, le, ro, F ) ;
		qry( pos*2+1, piv+1, B, le, ro, F ) ;
	}
}

void inicia( int pos, int A, int B ) {
	if( A>B )
		return ;

	int piv = (A+B)/2 ;

	segT[pos][0] = B-A+1 ;

	if( A==B )
		return ;

	inicia( pos*2, A, piv ) ;
	inicia( pos*2+1, piv+1, B ) ;
}

int main() {
	int N, Q ;

	scanf("%d%d", &N, &Q ) ;

	inicia( 1, 0, N-1 ) ;

	while( Q ) {
		Q -- ;
		int x, a, b ;
		scanf("%d%d%d", &x, &a, &b ) ;
		if( x==0 ) {
			act( 1, 0, N-1, a, b ) ;
		}
		else {
			res = 0 ;
			qry( 1, 0, N-1, a, b, 0 ) ;
			printf("%d\n", res ) ;
		}
	}

	return 0 ;
}

