#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;  

void solve(  int T  ) {
	int N, arr[1000] ;
	int i, x ;
	int res = 0 ;
	
	scanf("%d", &N ) ;
	for( i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
	printf("Case #%d: ", T )  ;
			
	x = 0 ;
	for( i=0; i<N; i++ ) {
		x ^= arr[i] ;
	}
	
	if( x!=0 ) {
		printf("NO\n" ) ;
		return ;
	}
	
	sort(  arr,  arr+N  ) ;
	for( i=1; i<N; i++ )
		res += arr[i] ;
	
	printf("%d\n",res ) ;
	
}

int main() {
	int T, i ;
	
	scanf("%d", &T ) ;
	for( i=1; i<=T; i++ ) 
		solve(i) ;
		
	return 0 ;
}
