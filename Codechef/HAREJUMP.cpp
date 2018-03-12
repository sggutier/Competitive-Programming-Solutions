#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 16
#define mod 1000000007LL

struct mat {
	long long arr[lim][lim] ;
};

mat operator*( mat &A, mat &B ) {
	mat res ;
	int i, j, k ;
	
	for( i=0; i<lim; i++ ) {
		for( j=0; j<lim; j++ ) {
			res.arr[i][j] = 0LL ;
			for( k=0; k<lim; k++ ) {
				res.arr[i][j] += A.arr[i][k]*B.arr[k][j] ;
				res.arr[i][j] %= mod ;
			}
		}
	}
	
	return res ;
}


mat bas ;


mat expBin( long long N ) {
	if( N==1LL )
		return bas ;
	mat temp = expBin( N/2LL ) ;
	temp = temp*temp ;
	if( N%2==1LL )
		temp = temp*bas ;
	return temp ;
}

void caso() {
	long long D ;
	int N ;
	
	for( int i=0; i<lim; i++ ) 
		for( int j=0; j<lim; j++ )
			bas.arr[i][j] = 0LL ;
	for( int i=1; i<lim; i++ )
		bas.arr[i-1][i] = 1LL ;
	
	cin >> D ;
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int a ;
		scanf("%d", &a ) ;
		bas.arr[lim-1][lim-a] ++ ;
	}
	
	bas = expBin( D ) ;
	
	cout << bas.arr[lim-1][lim-1] << endl ;
}


int main() {
	int T ;
	
	scanf("%d", &T ) ;
	
	for( int i=0; i<T; i++ ) {
		caso() ;
	}
	
	return 0 ;
}

