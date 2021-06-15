#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second
#define lim 500

int N, K ;
par arr[lim] ;

int main() {
	par lug ;
	int res = 0 ;
	
	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &arr[i].f, &arr[i].s ) ;
		arr[i].f *= -1 ;
	}
	
	sort( arr, arr+N ) ;
	lug = arr[K-1] ;
	for( int i=0; i<N; i++ ) {
		if( arr[i]==lug )
			res ++ ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
