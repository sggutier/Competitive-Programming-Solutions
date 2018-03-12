#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;
const int lim = 100005 ;
const int limK = 2000006 ;

int N ;
int arr[lim] ;
char fnd[limK] ;

void busca( int ini, int fin ) {
	if( ini==fin ) {
		fnd[arr[ini]] = 1 ;
		return ;
	}
	int piv = (ini+fin)/2 ;
	vector <int> le, ro ;

	busca( ini, piv ) ;
	busca( piv+1, fin ) ;
	
	for( int i=piv, crg=0; i>=ini; i-- ) {
		int crg2 = crg | arr[i] ;
		if( crg2==crg )
			continue ;
		le.push_back(crg2) ;
		crg = crg2 ;
	}

	for( int i=piv+1, crg=0; i<=fin; i++ ) {
		int crg2 = crg | arr[i] ;
		if( crg2==crg )
			continue ;
		ro.push_back(crg2) ;
		crg = crg2 ;
	}

	for( int i=0; i<le.size(); i++ )
		for( int j=0; j<ro.size(); j++ )
			fnd[ le[i] | ro[j] ] = 1 ;
}

int main() {
	int res = 0 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;

	busca( 0, N-1 ) ;

	for( int i=0; i<limK; i++ )
		if( fnd[i] )
			res ++ ;

	printf("%d\n", res ) ;

	return 0 ;
}
