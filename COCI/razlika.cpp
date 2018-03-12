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
const int lim = 1000006 ;
#define par pair<int,int>
#define f first
#define s second

int N, K ;
int arr[lim] ;
priority_queue <par> qMin ;

int main() {
	int res = (1<<30) ;

	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
	K = N-K-1 ;

	sort( arr, arr+N ) ;
	for( int i=0; i<N; i++ ) {
		if( i ) 
			qMin.push( par(-arr[i]+arr[i-1],i-1) ) ;
		if( i<K )
			continue ;
		int tmp = arr[i]-arr[i-K] ;
		while( qMin.top().s<i-K )
			qMin.pop() ;
		tmp -= qMin.top().f ;
		res = min( res, tmp ) ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}

