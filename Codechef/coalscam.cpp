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
const int limN = 5005 ;
const int limE = 20005 ;

struct edg {
	int ini, fin, dis ;
	edg() {
	}
	edg( int _ini, int _fin, int _dis ) {
		ini = _ini ;
		fin = _fin ;
		dis = _dis ;
	}
};

bool operator<( edg A, edg B ) {
	if( A.dis != B.dis )
		return A.dis < B.dis ;
	if( A.ini != B.ini ) 
		return A.ini < B.ini ;
	return A.fin < B.fin ;
}


int N, eC, eO ;
edg chef[limE], othr[limE] ;
int parent[limN], nSons[limN] ;

int node_root( int x ) {
	while( parent[x]!=x )
		x = parent[x] ;
	return x ;
}

void join( int a, int b ) {
	a = node_root(a) ;
	b = node_root(b) ;
	if( nSons[a]<nSons[b] ) 
		swap( a, b ) ;
	nSons[a] = max( nSons[a], nSons[b]+1 ) ;
	parent[b] = a ;
}

void test_case() {
	long long rA=0LL, rB=0LL ;

	scanf("%d%d%d", &N, &eO, &eC ) ;
	for( int i=0; i<N; i++ ) {
		parent[i] = i ;
		nSons[i] = 0 ;
	}
	for( int i=0; i<eO; i++ ) 
		scanf("%d%d%d", &othr[i].ini, &othr[i].fin, &othr[i].dis ) ;
	for( int i=0; i<eC; i++ ) 
		scanf("%d%d%d", &chef[i].ini, &chef[i].fin, &chef[i].dis ) ;

	sort( chef, chef+eC ) ;
	sort( othr, othr+eO ) ;
	reverse( chef, chef+eC ) ;

	for( int i=0; i<eC; i++ ) {
		if( node_root(chef[i].ini) == node_root(chef[i].fin)   )
			continue ;
		join( chef[i].ini, chef[i].fin ) ;
		rA += chef[i].dis ;
	}
	for( int i=0; i<eC; i++ ) {
		if( node_root(othr[i].ini) == node_root(othr[i].fin)   )
			continue ;
		join( othr[i].ini, othr[i].fin ) ;
		rB += othr[i].dis ;
	}

	for( int i=1, k=node_root(0); i<N; i++ ) {
		if( node_root(i)!=k ) {
			printf("Impossible\n" ) ;
			return ;
		}
	}

	printf("%lld %lld\n", rA, rB+rA ) ;

}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) 
		test_case() ;

	return 0 ;
}


