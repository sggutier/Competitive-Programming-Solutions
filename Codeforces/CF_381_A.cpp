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
const int lim = 1005 ;

int N ;
int arr[lim] ;

int main() {
	int sum[] = { 0, 0 } ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;

	for( int i=0, j=N-1, t=0; i<=j; t=(t==0) ) {
		sum[t] += max( arr[i], arr[j] ) ;
		if( arr[i] > arr[j] )
			i ++ ;
		else
			j -- ;
	}

	printf("%d %d\n", sum[0], sum[1] ) ;

	return 0 ;
}

