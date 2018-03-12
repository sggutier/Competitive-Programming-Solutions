#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
const int lim = 100005 ;

int N ;
long long carg[lim], cmb[lim] ;
bool usd[lim] ;

void act( int T ) {
	for( int i=0; i<=N; i++ )
		if( usd[i] )
			carg[i] += cmb[i]*T ;
}

long long query( int ini, int fin ) {
	long long res = -(1LL<<62) ;
	for( int i=ini; i<=fin; i++ )
		if( usd[i] )
			res = max( res, carg[i] ) ;
	return res ;
}

int main() {
	int Q ;
	int ult = 0 ;
	
	scanf("%d%d", &N, &Q ) ;
	for( int i=0; i<Q; i++ ) {
		int a, b ;
		scanf("%d%d", &a, &b ) ;
		if( ult==0 )
			ult = b ;
		act( b-ult ) ;
		if( a==1 ) {
			int pos ;
			scanf("%d", &pos ) ;
			scanf("%lld%lld", &cmb[pos], &carg[pos] ) ;
			usd[pos] = 1 ;
		}
		else {
			int ini, fin ;
			long long tmp ;
			scanf("%d%d", &ini, &fin ) ;
			if( ini>fin )
				swap( ini, fin ) ;
			tmp = query( ini, fin ) ;
			if( tmp==-(1LL<<62)  )
				printf("nema\n" ) ;
			else
				printf("%lld\n", tmp ) ;
		}
		ult = b ;
	}
	
	return 0 ;
}
