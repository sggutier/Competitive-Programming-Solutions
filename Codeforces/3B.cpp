#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
#define lim 100007
typedef pair<int,int> par ;
#define f first
#define s second


int main() {
	int N, K=0, C=0, v ;
	par ka[lim], ca[lim] ;
	int ar[lim] ;
	int i, j ;
	int a, b ;
	int res = 0 ;
	
	scanf("%d%d", &N, &v ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d%d", &a,&b ) ;
		if( a==1 ) {
			ka[K].f = b ;
			ka[K].s = i ;
			K ++ ;
		}
		else {
			ca[C].f = b ;
			ca[C].s = i ;
			C ++ ;
		}
	}
	
	
	sort( ka, ka+K ) ;
	sort( ca, ca+C ) ;
	K --, C-- ;
	N = 0 ;
	if( v%2 && K>=0 ) {
		v -- ;
		ar[N++] = ka[K].s ;
		res += ka[K].f ;
		K -- ;
	}
	while( K>=1 && C>=0 && v>1 ) {
		v -= 2 ;
		if( ka[K].f + ka[K-1].f > ca[C].f ) {
			res += ka[K].f + ka[K-1].f ;
			ar[N++] = ka[K].s ;
			ar[N++] = ka[K-1].s ;
			K -= 2 ;
		}
		else {
			res += ca[C].f ;
			ar[N++] = ca[C].s ;
			C -- ;
		}
	}
	while( v>1 && C>=0 ) {
		v -= 2 ;
		res += ca[C].f ;
		ar[N++] = ca[C].s ;
		C -- ;
	}
	while( v>0 && K>=0 ) {
		v -- ;
		ar[N++] = ka[K].s ;
		res += ka[K].f ;
		K -- ;
	}
	
	printf("%d\n", res ) ;
	for( i=0; i<N; i++ ) 
		printf("%d ", ar[i]+1 ) ;
	printf("\n") ;
	
	return 0 ;
}
