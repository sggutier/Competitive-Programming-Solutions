#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 100005

int res[lim] ;
int gana[lim] ;

int DP( int N ) {
	if( gana[N] != -1 )
		return res[N];
	
	int i, j ;
	int a, w ;
	
	/*printf("%d\n", N ) ;
	for( i=2; ( (i-1)*i )/2 <= N; i++  )  {
		if(     ( N - ( (i-1)*i )/2 ) <= 0   ||     ( N - ( (i-1)*i )/2 ) %i    )
			continue ;
		a = ( N - ( (i-1)*i )/2 ) / i ;
		w = 0 ;
		for( j=0; j<i; j++, a++ )  {
			printf("%d ", a ) ;
		}
		printf("\n" ) ;
	}
	printf("----------\n" ) ;*/
	
	
	for( i=2; ( (i-1)*i )/2 < N; i++  )  {
		if(   ( N - ( (i-1)*i )/2 ) %i    )
			continue ;
		a = ( N - ( (i-1)*i )/2 ) / i ;
		w = 0 ;
		for( j=0; j<i; j++, a++ )  {
			if( DP(a)  )
				w ++ ;
		}
		
		if( w%2==0 ) {
			gana[N] = 1 ;
			res[N] = i ;
			return 1 ;
		}
	}
	
	return gana[N] = 0 ;
}

int main() {
	int N ;
	
	fill( gana, gana+lim, -1 ) ;
	
	scanf("%d", &N ) ;
	
	if( DP(N) )
		printf("%d\n", res[N] ) ;
	else
		printf("-1\n" ) ;
		
	return 0 ;
}
