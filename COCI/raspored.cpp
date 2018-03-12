#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 10005

int P ;
int lun[lim], bak[lim] ;
int ord[lim] ;

long long calc() {
	long long W = P, res=0LL ;
	
	for( int i=0; i<P; i++ ) 	
		res += lun[i] ;
	for( int i=0; i<lim; i++ ) {
		for( int j=0; j<ord[i]; j++, W-- ) {
			res -= i*W ;
		}
	}
	
	return res ;
}

int main() {
	int C ;
	int x, y, z ;
	
	scanf("%d%d", &P, &C ) ;
	for( int i=0; i<P; i++ ) {
		scanf("%d%d", &lun[i], &bak[i] ) ;
		ord[bak[i]] ++ ;
	}
	
	printf("%lld\n", calc() ) ;
	for( int i=0; i<C; i++ ) {
		scanf("%d%d%d", &x, &y, &z ) ;
		x -- ;
		ord[ bak[x] ] -- ;
		lun[x] = y ;
		bak[x] = z ;
		ord[z] ++ ;
		printf("%lld\n", calc() ) ;
	} 
	
	return 0 ;
}
