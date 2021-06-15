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
const int lim = 100005 ;

int N, R=0 ;
int arr[lim] ;
int res[lim] ;

int main() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] );

	sort( arr, arr+N ) ;
	
	for( int i=0, ult=-5; i<N; i++ ) {
		if( arr[i]!=ult )  {
			res[R++] = arr[i] ;
			ult = arr[i] ;
			arr[i] = -1 ;
		}
	}
	for( int i=N-2; i>=0; i-- ) {
		if( arr[i]!=arr[i+1] && arr[i]!=-1 ) 
		       res[R++] = arr[i] ;	
	}

	printf("%d\n", R ) ;
	for( int i=0; i<R; i++ )
		printf("%d ", res[i] ) ;
	printf("\n" ) ;

	return 0 ;
}

