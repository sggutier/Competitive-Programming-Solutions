#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 1524289 ;
const long long inf = (1LL<<60) ;

int N ;
long long le[lim], ro[lim] ;
long long K[lim] ;
long long res[lim] ;

void limpia( int ini, int fin, long long val ) {
	for( ; ini<=fin; ini++ ) {
		le[ini] = inf ;
		ro[ini] = inf ;
		res[ini] = inf ;
	}
}

void preCalc( int ini, int fin, int tam ) {
	int act ;

	for( int pos=0; pos<=fin; pos++ ) {
		K[pos] = inf ;
		for( int j=0; pos+j<tam && j<tam; j++ ) {
			K[pos] = min( K[pos], res[pos+j] ) ;
		}
	}

	return ;

	for( int pos=0; pos<=fin; pos+=tam ) {
		act = pos+tam-1 ;
		le[act] = res[act] ;
		ro[act] = res[act] ;
		for( int i=1; i<tam; i++ ) {
			le[act-i] = min( le[act-i+1], res[act-i] ) ;
			ro[act+i] = min( ro[act+i-1], res[act+i] ) ;
		}
		for( int i=0; i<tam; i++ ) 
			K[pos+i] = min( le[pos+i], ro[act+i] ) ;
	}
}

int main() {
	int pot=2, ant=1 ;
	long long foo = inf ;
	int ini, fin ;

	limpia( 0, lim-1, inf ) ;

	scanf("%d", &N ) ;
	if( N>1000 ) {
		printf("0\n" ) ;
		return 0 ;
	}
	for( int i=0; i<2 && i<N; i++ ) {
		long long tmp ;
		scanf("%lld", &tmp ) ;
		res[i] = tmp + 0LL ;
		if( i )
			res[i] += res[i-1] ;
	}

	preCalc( 0, pot-1, ant ) ;
	ini = 0 ;
	fin = 0 ;
	for( int i=2; i<N; i++, ini++, fin++ ) {
		long long tmp ;
		scanf("%lld", &tmp ) ;
		if( pot*2<=i ) {
			ant *= 2 ;
			pot *= 2 ;
			preCalc( 0, pot-1, ant ) ;
			foo = inf ;
			ini = 0 ;
			fin = ant-1 ;
		}
		if( fin>=pot )
			foo = min( foo, res[fin] ) ;
		res[i] = min( K[ini], foo ) + tmp ;
	}

	cout << res[N-1] << endl ;

	return 0 ;
}


