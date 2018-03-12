#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define lim 64
#define lim2 128
#define lim3 100005

struct gre {
	int carg[lim2] ;
	int query( int ini, int fin, int pos, int a, int b ) {
		if( ini==a && fin==b ) {
			//printf("%d %d %d %d %d\n", ini,  fin, pos, a, b ) ;
			return carg[pos] ;
		}
		int mit = (a+b)/2 ;
		if( ini<=mit && fin<=mit )
			return query( ini, fin, pos*2+1, a, mit ) ;
		else if( ini>mit && fin>mit )
			return query( ini, fin, pos*2+2, mit+1, b ) ;
		else
			return query( ini, mit, pos*2+1, a, mit) + query( mit+1, fin, pos*2+2, mit+1, b) ;
	}
	void mete( int g, int pos, int a, int b ) {
		carg[pos]++ ;
		if( a==g && b==g )  {
			return ;
		}
		int mit = (a+b)/2 ;
		if( g<=mit )
			mete( g, pos*2+1, a, mit ) ;
		else
			mete( g, pos*2+2, mit+1, b ) ;
	}
};

struct red {
	gre carg[lim2] ;
	int query( int ini, int fin, int pos, int a, int b, int ini2, int fin2 ) {
		if( ini==a && fin==b ) {
			//printf("%d %d %d %d %d %d %d\n", ini,  fin, pos, a, b, ini2, fin2 ) ;
			return carg[pos].query(ini2,fin2,0,0,lim-1) ;
		}
		int mit = (a+b)/2 ;
		if( ini<=mit && fin<=mit )
			return query( ini, fin, pos*2+1, a, mit, ini2, fin2 ) ;
		else if( ini>mit && fin>mit )
			return query( ini, fin, pos*2+2, mit+1, b, ini2, fin2 ) ;
		else
			return query( ini, mit, pos*2+1, a, mit, ini2, fin2 ) + query( mit+1, fin, pos*2+2, mit+1, b, ini2, fin2 ) ;
	}
	void mete( int r, int g, int pos, int a, int b ) {
		carg[pos].mete(g,0,0,lim-1) ;
		if( a==r && b==r )  {
			return ;
		}
		int mit = (a+b)/2 ;
		if( r<=mit )
			mete( r, g, pos*2+1, a, mit ) ;
		else
			mete( r, g, pos*2+2, mit+1, b ) ;
	}
};

struct blu {
	red carg[lim] ;
	int query( int P, int ini, int fin, int ini2, int fin2  ) {
		int res = 0 ;
		int tmp[lim] ;
		for( int i=0, W=0; i<lim; i++ ) {
			tmp[i] = carg[i].query(ini,fin,0,0,lim-1,ini2,fin2) ;
			W += tmp[i] ;
			if( i-P>=0 )
				W -= tmp[i-P] ;
			//printf("%d ", W ) ;
			res = max( res,  W ) ;
		}
		//printf(" -> %d\n", res ) ;
		return res ;
	}
	void mete( int b, int r, int g ) {
		carg[b].mete( r, g, 0, 0, lim-1 ) ;
	}
};

blu segm ;

bool sePuede( int P, int K, int &x, int &y, int &z ) {
	for( int i=0; i+P<lim; i++ ) {
		for( int j=0; j+P<lim; j++ ) {
			if( segm.query(P, i, i+P, j, j+P ) >= K  )  {
				x = i ;
				y = j ;
				z = P ;
				return 1 ;
			}
		}
	}
	return 0 ;
}

int main() {
	int N, K ;
	int r[lim3], g[lim3], b[lim3] ;
	int ini, fin, piv ;
	int x, y, z ;
	
	scanf("%d%d", &N,&K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d%d", &r[i], &g[i], &b[i] ) ;
		segm.mete( b[i], r[i], g[i] ) ;
		//segm.mete( i, i, 3, 0, 0, lim-1 ) ;
	}
	
	cout << "Hiar" << endl ;
	ini = 0, fin=lim-1; 
	while( ini<fin ) {
		printf("%d %d\n", ini, fin ) ;
		piv = (ini+fin)/2 ;
		if( sePuede(piv,K,x,y,z) )
			fin = piv ;
		else
			ini = piv+1 ;
	}
	printf("%d\n", ini ) ;
	
	return 0 ;
}

