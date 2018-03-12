#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std ;
#define lim 100005

int main() {
	int N, K ;
	int arr[lim] ;
	int dis = 0, mit=0 ;
	int res = 0 ;
	
	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		if( arr[i]==K )
			mit = i+1 ;
	}
	
	if( mit==0 ) {
		arr[N++] = K ;
		res ++ ;
	}
	
	sort( arr, arr+N ) ;
	mit = (N-1)/2 ;
	if( arr[mit]==K ) {
		cout << res << endl ;
		return 0 ;
	}
	else if( arr[mit]<K ) {
		int tmp = mit ;
		dis = mit ;
		for( ; arr[mit]!=K && mit<N; mit++ ) ;
		dis = mit - (N-mit-1) ;
		mit = tmp ;
	}
	else if( arr[mit]>K ) {
		int tmp = mit ;
		dis = mit ;
		for( ; arr[mit]!=K && mit>=0; mit-- ) ;
		dis = (N-mit-1) - mit-1 ;
		mit = tmp ;
	}
	
	res += dis ;
		
	printf("%d\n", res ) ;
	
	return 0 ;
}


