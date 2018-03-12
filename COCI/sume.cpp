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
const int lim = 1005 ;

int N ;
int arr[lim][lim] ;
int res[lim] ;

int main() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		for( int j=0; j<N; j++ )
			scanf("%d", &arr[i][j] ) ;

	if( N==2 ) {
		printf("%d %d\n", 1, arr[0][1]-1 ) ;
		return 0 ;
	}

	res[0] = (arr[0][1]-arr[1][2]+arr[0][2])/2 ;
	for( int i=1; i<N; i++ )
		res[i] = arr[0][i]-res[0] ;

	for( int i=0; i<N; i++ )
		printf("%d ", res[i] ) ;
	printf("\n" ) ;

	return 0 ;
}


