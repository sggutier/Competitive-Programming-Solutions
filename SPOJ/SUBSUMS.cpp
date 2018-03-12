#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
using namespace std ;
const int lim = 20 ;
const int limB = (1<<lim) ;

int nA=0, nB=0 ;
long long A[limB], B[limB] ;

int main() {
	int N, K  ;
	long long X, Y ;
	int arr[lim*3] ;
	long long res = 0LL ;

	scanf("%d", &N ) ;
	scanf("%d", &K ) ;
	X = K +0LL ;
	scanf("%d", &K ) ;
	Y = K +0LL ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] );

	K = N/2 ;
	K = N-K ;
	for( int i=0; i<(1<<K); i++ ) {
		long long tmp = 0LL ;
		for( int a=0; a<K; a++ ) 
			if( (1<<a)&i )
				tmp += arr[a] ;
		A[nA++] = tmp ;
	}

	for( int i=0; i<(1<<(N-K)); i++ ) {
		long long tmp = 0LL ;
		for( int a=0; a<(N-K); a++ ) 
			if( (1<<a)&i )
				tmp += arr[a+K] ;
		B[nB++] = tmp ;
	}

	sort( B, B+nB ) ;

	for( int i=0; i<nA; i++ ) {
		int le, ro ;
		int ini, fin, piv ;
		
		ini = 0 ;
		fin = nB-1 ;
		while( ini<fin ) {
			piv = (ini+fin)/2 ;
			if( B[piv]<X-A[i] )
				ini = piv+1 ;
			else
				fin = piv ;
		}
		le = ini ;

		ini = 0 ;
		fin = nB-1 ;
		while( ini<fin ) {
			piv = (ini+fin)/2 +1 ;
			if( B[piv]>Y-A[i] )
				fin = piv-1 ;
			else
				ini = piv ;
		}
		ro = ini ;

		if( A[i]+B[le]>Y || A[i]+B[ro]<X )
			continue ;
		
		res += ro-le+1 ;
	}

	cout << res << endl ;

	return 0 ;
}
