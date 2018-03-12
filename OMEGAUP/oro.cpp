#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 30 ;

int N, W ;
int arr[lim] ;

int main() {
	int res = (1<<30) ;
	
	scanf("%d%d", &N, &W ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
		
	for( int i=0; i<(1<<N); i++ ) {
		int tmp = 0 ;
		for( int j=0; j<N; j++ )
			if( (1<<j) & i )
				tmp += arr[j] ;
		if( tmp>=W )
			res = min( res, tmp-W ) ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
