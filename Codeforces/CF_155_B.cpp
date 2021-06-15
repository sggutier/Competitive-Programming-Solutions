#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second

int N ;
par arr[1005] ;

int main() {
	int res = 0, carg=1 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d%d", &arr[i].s, &arr[i].f ) ;
		
	sort( arr, arr+N ) ;
	for( int i=N-1; i>=0 && carg; i--, carg-- ) {
		res += arr[i].s ;
		carg += arr[i].f ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
