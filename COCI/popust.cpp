#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second
const int lim = 500005 ;

int N ;
par arr[lim] ;
int minW[lim] ;

int main() {
	long long W=0LL, K=-(1LL<<62) ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &arr[i].s, &arr[i].f ) ;
	}
	
	sort( arr, arr+N ) ;
	minW[N] = (1<<30) ;
	for( int i=N-1; i>=0; i-- ) {
		minW[i] = min( minW[i+1], arr[i].s ) ;
	}
	
	for( int i=0; i<N; i++ ) {
		K = max( K,  (long long) (arr[i].f - arr[i].s)  ) ;
		printf("%lld\n", min( W+arr[i].f-K, W+minW[i] )   ) ; 
		W += arr[i].f ;
	}
	
	return 0 ;
}
