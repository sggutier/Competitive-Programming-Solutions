#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
using namespace std ;
#define lim 10005

int N, K ;
int arr[lim] ;

int minT( int res, int ini, int fin ) {
	while( ini<fin  &&  arr[ini] == arr[fin]     )  {
		ini ++, fin-- ;
	}
	if( ini>=fin ) {
		return 0 ;
	}
	if( !res ) {
		return 1000 ;
	}
	return min(  minT( res-1, ini+1, fin ),  minT( res-1, ini, fin-1  )    )  + 1 ;
}

int main() {
	int i ;
	
	scanf("%d%d", &N, &K ) ;
	for( i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;
		
	i = minT( K, 0, N-1 ) ;
	
	if( i==0 ) 
		printf("Demasiado facil\n" ) ;
	else if( i>K ) 
		printf("Demasiado dificil\n" ) ;
	else
		printf("%d\n", i ) ;
		
	return 0 ;
}
