#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 500005 ;

int N ;
int arr[lim] ;

int main() {
	int res = 0 ;
	int i, f ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
		
	sort( arr, arr+N ) ;
	f = N-1 ;
	i = 0 ;
	while( i<f ) {
		if( arr[i]==0 ) {
			i++ ;
			continue ;
		}
		arr[i] -- ;
		f -- ;
		res ++ ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
