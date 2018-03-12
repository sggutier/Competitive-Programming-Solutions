#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
#define lim 50005

int N ;
int arr[lim][2] ;
int R[lim] ;
int ref[lim][2] ;
bool usd[lim] ;
int rep[lim*2] ;
int t, c ;

void busca( int pos ) {
	t ++ ;
	usd[pos] = 1 ;
	if( ref[pos][0] != -1  &&  !usd[ ref[pos][0]  ]   ) {
		if( arr[ ref[pos][0] ][0] == arr[pos][0]  ||  arr[ ref[pos][0] ][1] == arr[pos][1]  )   {
			swap( arr[ ref[pos][0] ][0],   arr[ ref[pos][0] ][1]   )  ;
			c ++ ;
		}
		busca( ref[pos][0]  )  ;
	}
	if( ref[pos][1] != -1  &&  !usd[ ref[pos][1]  ]   ) {
		if( arr[ ref[pos][1] ][0] == arr[pos][0]  ||  arr[ ref[pos][1] ][1] == arr[pos][1]  )   {
			swap( arr[ ref[pos][1] ][0],   arr[ ref[pos][1] ][1]   )  ;
			c ++ ;
		}
		busca( ref[pos][1]  )  ;
	}
}

int main() {
	int i, j ;
	int res = 0 ;
	int tmp ;

	for( i=0; i<lim; i++ ) {
		ref[i][0] = -1 ;
		ref[i][1] = -1 ;
	}
	for( i=2*lim-1; i>=0; i-- ) {
		rep[i] -- ;
	}
	
	scanf("%d",&N ) ;
	for( j=0; j<2; j++ ) {
		for( i=0; i<N; i++ ) {
			scanf("%d", &arr[i][j] ) ;
			if( rep[ arr[i][j] ] == -1 ) {
				rep[ arr[i][j] ] = i ;
			}
			else {
				tmp = rep[ arr[i][j] ] ;
				ref[i][ R[i]++ ] = tmp ;
				ref[tmp][ R[tmp]++ ] = i ;
			}
		}
	}
	
	for( i=0; i<N; i++ ) {
		if( usd[i] ) 
			continue ;
		t = 0 ;
		c = 0 ;
		busca( i ) ;
		c = min( c, t-c ) ;
		res += c ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
