#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define limD 1005
#define limN 100005

struct bit {
	int dat[limD][limD] ;
	bit() {
	}
	void mete( int r, int c, int nov ) {
		for( int i=r; i<limD; i += (i & -i)  )
			for( int j=c; j<limD; j += (j & -j)   )
				dat[i][j] += nov ;
	}
	int saca( int r, int c ) {
		int res = 0 ;
		for( int i=r; i; i -= (i & -i)  )
			for( int j=c; j; j -= (j & -j)   )
				res += dat[i][j] ;
		return res ;
	}
	int query( int xIni, int yIni, int xFin, int yFin ) {
		xIni--, yIni -- ;
		return saca( xFin, yFin ) + saca( xIni, yIni ) - saca( xFin, yIni ) - saca( xIni, yFin ) ;
	}
	void reset() {
		memset( dat, 0, sizeof(dat) ) ;
	}
};

struct pto {
	int tip, ord ;
	int xIni, xFin, yIni, yFin ;
	pto() {
	}
	pto( int a, int b, int c, int d, int e, int f ) {
		tip = a ;
		ord = b ;
		xIni = c ;
		yIni = d ;
		xFin = e ;
		yFin = f ;
	}
};

bool operator<( const pto &A, const pto &B ) {
	if( A.ord != B.ord )
		return A.ord < B.ord ;
	return A.tip < B.tip ;
}

bit inf, sup ;
int W ;
pto pts[2*limN] ;

long long intersec() {
	long long res = 0LL ;
	
	inf.reset() ;
	sup.reset() ;
	sort( pts, pts+W ) ;
	
	for( int i=0; i<W; i++ ) {
		if( pts[i].tip != 3 ) 
			res += inf.query( pts[i].xIni, 1, pts[i].xFin, pts[i].yFin ) - sup.query( pts[i].xIni, 1, pts[i].xFin, pts[i].yIni-1 ) ;
		if( pts[i].tip == 1 ) {
			inf.mete( pts[i].xIni, pts[i].yIni, 1 ) ;
			sup.mete( pts[i].xIni, pts[i].yFin, 1 ) ;
		}
		if( pts[i].tip == 3 ) {
			inf.mete( pts[i].xIni, pts[i].yIni,-1 ) ;
			sup.mete( pts[i].xIni, pts[i].yFin,-1 ) ;
		}
	}
	
	return res ;
}

int main() {
	int N ;
	int arr[limN][6] ;
	long long res = 0LL ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		for( int j=0; j<6; j++ ) 
			scanf("%d", &arr[i][j] ) ;
		for( int j=0; j<3; j++ )
			if( arr[i][j] > arr[i][j+3] )
				swap( arr[i][j] , arr[i][j+3] ) ;
	}
	
	
	for( int k=0; k<3; k++ ) {
		int k2=(k+1)%3, k3=(k2+1)%3 ;
		W = 0 ;
		for( int i=0; i<N; i++ ) {
			if( arr[i][k] == arr[i][k+3] ) {
				pts[W++] = pto( 1, arr[i][k2  ], arr[i][k], arr[i][k3], arr[i][k+3], arr[i][k3+3] ) ;
				pts[W++] = pto( 3, arr[i][k2+3], arr[i][k], arr[i][k3], arr[i][k+3], arr[i][k3+3] ) ;
			}
			else if( arr[i][k2]==arr[i][k2+3] ) {
				pts[W++] = pto( 2, arr[i][k2  ], arr[i][k], arr[i][k3], arr[i][k+3], arr[i][k3+3] ) ;
			}
		}
		res += intersec() ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
