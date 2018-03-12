#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 52 ;
const long long mod = 1000000007LL ;

struct mat {
	int N, M ;
	int arr[lim][lim] ;
};

mat operator*( mat A, mat B ) {
    mat C ;
    long long x, y ;
	C.N = A.M ;
	C.M = B.N ;
	for( int i=0; i<C.N; i++ ) {
		for( int j=0; j<C.M; j++ ) {
			C.arr[i][j] = 0LL ;
			for( int k=0; k<A.M; k++ ) {
			    x = 0LL + A.arr[i][k] ;
			    y = 0LL + B.arr[k][j] ;
				C.arr[i][j] = (C.arr[i][j] + x*y)%mod ;
			}
		}
	}

	return C ;
}

mat ExpBin( mat &W, long long N ) {
	if( N==1LL ) {
		return W ;
	}
	if( N==0LL ) {
	    for( int i=0; i<W.M; i++ ) {
            for( int j=0; j<W.M; j++ )
                W.arr[i][j] = 0 ;
            W.arr[i][i] = 1LL ;
	    }
        return W ;
	}
	mat tmp = ExpBin( W, N/2LL ) ;
	tmp = tmp*tmp ;
	if( N%2LL )
		tmp = tmp*W ;

	return tmp ;
}

int main() {
	mat W, res ;
	int K ;
	long long R = 0LL, X ;

	cin >> X >> W.N >> K ;
	W.M = W.N ;
	for( int i=0; i<W.N; i++ )
		for( int j=0; j<W.M; j++ )
			W.arr[i][j] = 1 ;

	for( int i=0; i<K; i++ ) {
		int x, y ;
		char tmp[10] ;

		scanf("%s", tmp ) ;
		if( tmp[0]>='a' && tmp[0]<='z' )
			x = tmp[0]-'a' ;
		else
			x = tmp[0]-'A'+26 ;
		if( tmp[1]>='a' && tmp[1]<='z' )
			y = tmp[1]-'a' ;
		else
			y = tmp[1]-'A'+26 ;
		W.arr[x][y] = 0 ;
	}

	res = ExpBin(W,X-1LL) ;
	for( int i=0; i<res.N; i++ ) {
		for( int j=0; j<res.N; j++ ) {
			R = (R+res.arr[i][j] )%mod ;
		}
	}

	cout << R << endl ;

	return 0 ;
}
