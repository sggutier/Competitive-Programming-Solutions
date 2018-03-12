#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define lim 100005
typedef pair<int,int> par;
#define f first
#define s second

int N, D ;
par vacas[lim] ;
int arr[lim], res=0 ;

void prueba( int pos, int cup ) {
	if( pos==N ) {
		int tmp = 0, i ;
		for( int i=0; i<N; i++ ) 
			arr[i] = vacas[i].f ;
		sort( arr, arr+N ) ;
		for( i=0; i<N && tmp<=D; tmp+=arr[i], i++ ) ;
		if( tmp<=D )
			i ++ ;
		res = max( res, i-1 ) ;
		return ;
	}
	prueba( pos+1, cup ) ;
	if( cup ) {
		swap( vacas[pos].s, vacas[pos].f ) ;
		prueba( pos+1, cup-1 ) ;
		swap( vacas[pos].s, vacas[pos].f ) ;
	}
}

int main() {
	freopen( "coupons.in", "r", stdin ) ;
	freopen( "coupons.out", "w", stdout ) ;
	
	int K ;
	
	scanf("%d%d%d", &N, &K, &D ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &vacas[i].f, &vacas[i].s ) ;
	}
	
	prueba( 0, K ) ;
	
	printf("%d\n", res ) ;
	
	return 0 ;
}


