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
const int lim = 500 ;
typedef pair<int,int> par ;
#define f first
#define s second

struct tip {
	int a, b, c ;
	tip() {
	}
	tip( int _a, int _b, int _c ) {
		a = _a ;
		b = _b ;
		c = _c ;
	}
};

bool operator<( tip A, tip B ) {
	if( A.a != B.a )
		return A.a < B.a ;
	if( A.b != B.b ) 
		return A.b < B.b ;
	return A.c < B.c ;
}

void caso( int N ) {
	int res = 0 ;
	tip arr[lim] ;
	int dp[lim] ;
	int W = 0 ;

	for( int i=0; i<N; i++ ) {
		int tmp[3] ;
		for( int j=0; j<3; j++ )
			scanf("%d", &tmp[j] );
		sort( tmp, tmp + 3  ) ;
		do {
			arr[W++] = tip( tmp[0], tmp[1], tmp[2] ) ;
		}while( next_permutation( tmp, tmp +3 ) ) ;
	}

	sort( arr, arr+W ) ;
	for( int i=W-1; i>=0; i-- ) {
		dp[i] = arr[i].c ;
		for( int j=i+1; j<W; j++ ) 
			if( arr[i].a < arr[j].a  &&  arr[i].b < arr[j].b ) 
				dp[i] = max( dp[i], dp[j] + arr[i].c ) ;
		res = max( res, dp[i] ) ;
	}

	printf("%d\n", res ) ;
}

int main() {
	int N ;

	scanf("%d", &N ) ;
	caso(N) ;

	return 0 ;
}
