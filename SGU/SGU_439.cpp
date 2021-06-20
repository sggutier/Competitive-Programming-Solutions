#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 1000006 ;
#define ull unsigned long long 
const ull bas = 27ULL ;

int tamA, tamB ;
char A[lim], B[lim] ;
ull haA[lim*2], haB[lim*2], haB2[lim*2] ;
ull pot[lim] ;

void precalc() {
	pot[0] = 1ULL ;
	for( int i=1; i<lim; i++ )
		pot[i] = pot[i-1]*bas ;
}

void sToHa( int N, char S[], ull arr[] ) {
	arr[0] = S[0]-'A' ;
	for( int i=1; i<N; i++ ) {
		arr[i] = arr[i-1]*bas + S[i]-'A' ;
	}
	for( int i=0; i<N; i++ ) {
		arr[N+i] = arr[N+i-1]*bas + S[i]-'A' ;
	}
}

ull subHa( int N, ull arr[], int pos, int k ) {
	ull res = arr[pos+k] ;
	if( pos )
		res -= arr[pos-1]*pot[k+1] ;
	return res ;
}

int main() {
	int resA, cmbA=(1<<30), dirA, resB = 0 ;

	scanf("%d%d", &tamA, &tamB ) ;
	scanf("%s%s", A, B ) ;

	precalc() ;

	sToHa( tamA, A, haA ) ;
	sToHa( tamB, B, haB ) ;

	for( int i=1; i<tamB; i++ ) {
		int ini=0, fin=tamB-1 ;
		while( ini<fin ) {
			int piv = (ini+fin)/2 ;
			if( subHa( tamB, haB, resB, piv ) == subHa( tamB, haB, i, piv )   )
				ini = piv+1 ;
			else
				fin = piv ;
		}
		if( B[(i+ini)%tamB] < B[(resB+ini)%tamB] )
			resB = i ;
	}

	for( int i=0; i<tamB; i++ )
		haB2[i] = subHa( tamB, haB, resB, i ) ;

	for( int i=0; i<tamA; i++ ) {
		int ini=0, fin=tamB, psb=0 ;
		while( ini<fin ) {
			int piv = (ini+fin)/2 ;
			if( haB2[piv] == subHa( tamA, haA, i, piv )   )
				ini = piv+1 ;
			else
				fin = piv ;
		}


		if( ini>=tamB-1 ) {
			psb = 1 ;
		}
		else {
			int rem = tamB-1 - (ini+1) ;
			if( subHa( tamA, haA, (i+ini+1)%tamA, rem ) == subHa( tamB, haB2, ini+1, rem )   )
				psb = 1 ;
		}

		if( psb ) {
			int x=i, y=-1 ;
			if( tamA-i-1<i ) {
				x = tamA-i-1 ;
				y = 1 ;
			}
			if( x<cmbA || (x==cmbA && y<dirA)  ) {
				resA = i ;
				cmbA = x ;
				dirA = y ;
			}
		}
	}

	for( int i=0; i<tamB; i++ )
		printf("%c", B[(resB+i)%tamB] ) ;
	printf("\n" ) ;
	for( int i=0; i<tamA; i++ )
		printf("%c", A[(resA+i)%tamA] ) ;
	printf("\n" ) ;

	return 0 ;
}


