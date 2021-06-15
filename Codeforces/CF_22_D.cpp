#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second
#define limN 1005

int main() {
	int N ;
	par arr[limN] ;
	bool usd[limN] ;
	int R=0 ;
	int res[limN] ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &arr[i].f, &arr[i].s ) ;
		if( arr[i].f > arr[i].s )
			swap( arr[i].f, arr[i].s ) ;
	}
	
	sort( arr, arr+N ) ;
	fill( usd, usd+N, 0 ) ;
	for( int i=0; i<N; i++ ) {
		if( usd[i] )
			continue ;
		int ini=arr[i].f, fin=arr[i].s ;
		for( int j=i+1; j<N; j++ ) {
			if( arr[j].f <= fin ) {
				usd[j] = 1 ;
				ini = max( ini, arr[j].f );
				fin = min( fin, arr[j].s );
			}
			else 
				break ;
		}
		res[R++] = ini ;
	}
	
	printf("%d\n", R ) ;
	for( int i=0; i<R; i++ ) 
		printf("%d ", res[i] ) ;
	cout << endl ;
	
	return 0 ;
}
