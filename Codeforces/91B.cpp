#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
#define lim 100007
typedef pair<int,int> par ;
#define f first
#define s second
#define inf (1<<30)

int bit[lim] ;
par arr[lim] ;
int ord[lim] ;
int res[lim] ;

void reg( int pos, int val ) {
	for( ; pos<lim; pos += (pos&-pos)  )
		bit[pos] = max( val, bit[pos] )  ;
}

int quer( int pos ) {
	int res = 0 ;
	for( ; pos; pos -= (pos&-pos)   )
		res = max( res, bit[pos] ) ;
	return res ;
}

int main() {
	int N ;
	
	scanf("%d", &N ) ;
	for( int i = 0; i<N; i++ ) {
		scanf("%d", &arr[i].f ) ;
		arr[i].s = i ;
	}
	
	sort( arr, arr+N ) ;
	
	ord[ arr[0].s ] = 1 ;
	for( int i=1; i<N; i++ ) {
		ord[ arr[i].s ] = ord[ arr[i-1].s ] ;
		if( arr[i].f != arr[i-1].f   ) {
			ord[ arr[i].s ] ++ ;
		}
	}
	
	for( int i = N-1; i>=0; i-- ) {
		int a = quer( ord[i]-1 ) ;
		if( a )
			res[i] = a-i-1 ;
		else
			res[i] = -1 ;
		reg( ord[i], i ) ;
	}
	
	for( int i=0; i<N; i++ ) 
		printf("%d ", res[i] ) ;
	printf("\n" ) ;
	
	return 0 ;
}
