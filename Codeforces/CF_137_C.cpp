#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define lim 100005

int N ;
par arr[lim] ;

int main() {
	int res = 0 ;
	int W = -(1<<30) ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &arr[i].f, &arr[i].s ) ;
	}
	
	sort( arr, arr+N ) ;
	for( int i=0; i<N; i++ ) {
		if( arr[i].s <= W )
			res ++ ;
		W = max( W, arr[i].s ) ;
	}
	
	printf("%d\n", res ) ;

	return 0 ;
}
