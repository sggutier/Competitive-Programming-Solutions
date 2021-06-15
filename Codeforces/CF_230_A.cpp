#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second

int main() {
	int S, N ;
	par arr[100000] ;

	scanf("%d%d", &S, &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d%d", &arr[i].f, &arr[i].s ) ;

	sort( arr, arr+N ) ;
	for( int i=0; i<N; i++ ) {
		if( arr[i].f>=S ) {
			printf("NO\n" ) ;
			return 0 ;
		}
		S += arr[i].s ;
	}

	printf("YES\n" ) ;

	return 0 ;
}
