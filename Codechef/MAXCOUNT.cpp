#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par;
#define f first
#define s second
#define lim 105

void caso() {
	int N, R=0 ;
	int arr[lim] ;
	par rep[lim] ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
		
	sort( arr, arr+N ) ;
	for( int i=0, j; i<N; i=j ) {
		for( j=i+1; j<N && arr[j]==arr[j-1]; j++ ) ;
		rep[R++] = par( i-j, arr[i] ) ;
	}
	sort( rep, rep+R ) ;
	
	printf("%d %d\n", rep[0].s, -rep[0].f ) ;
}

int main() {
	int T ;
	
	for( scanf("%d", &T );  T;  T--  )
		caso() ;
		
	return 0 ;
}
