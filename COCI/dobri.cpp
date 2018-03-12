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
const int limN = 5000 ;
const int limW = 300000 ;

int N ;
int arr[limN+5] ;
bool usd[limW*2 + 5 ] ;

int main() {
	int res = 0 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;

	usd[ arr[0]*2 + limW ] = 1 ;
	for( int i=1; i<N; i++ )  {
		int K=arr[i] ;
		for( int j=0; j<i; j++ ) {
			if( usd[ K-arr[j] + limW ] ) {
				res ++ ;
				break ;
			}
		}
		for( int j=0; j<=i; j++ )
			usd[ K + arr[j] + limW ] = 1 ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}


