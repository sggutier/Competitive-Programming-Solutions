#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define lim 128
#define lim2 256
#define lim3 100005

struct gre {
	int carg[lim2] ;
	short query( short ini, short fin, short pos, short a, short b ) {
		if( ini==a && fin==b ) {
			//prshortf("%d %d %d %d %d\n", ini,  fin, pos, a, b ) ;
			return carg[pos] ;
		}
		short mit = (a+b)/2 ;
		if( ini<=mit && fin<=mit )
			return query( ini, fin, pos*2+1, a, mit ) ;
		else if( ini>mit && fin>mit )
			return query( ini, fin, pos*2+2, mit+1, b ) ;
		else
			return query( ini, mit, pos*2+1, a, mit) + query( mit+1, fin, pos*2+2, mit+1, b) ;
	}
	void mete( short g, short pos, short a, short b ) {
		carg[pos]++ ;
		if( a==g && b==g )  {
			return ;
		}
		short mit = (a+b)/2 ;
		if( g<=mit )
			mete( g, pos*2+1, a, mit ) ;
		else
			mete( g, pos*2+2, mit+1, b ) ;
	}
};

struct red {
	gre carg[lim2] ;
	short query( short ini, short fin, short pos, short a, short b, short ini2, short fin2 ) {
		if( ini==a && fin==b ) {
			//prshortf("%d %d %d %d %d %d %d\n", ini,  fin, pos, a, b, ini2, fin2 ) ;
			return carg[pos].query(ini2,fin2,0,0,lim-1) ;
		}
		short mit = (a+b)/2 ;
		if( ini<=mit && fin<=mit )
			return query( ini, fin, pos*2+1, a, mit, ini2, fin2 ) ;
		else if( ini>mit && fin>mit )
			return query( ini, fin, pos*2+2, mit+1, b, ini2, fin2 ) ;
		else
			return query( ini, mit, pos*2+1, a, mit, ini2, fin2 ) + query( mit+1, fin, pos*2+2, mit+1, b, ini2, fin2 ) ;
	}
	void mete( short r, short g, short pos, short a, short b ) {
		carg[pos].mete(g,0,0,lim-1) ;
		if( a==r && b==r )  {
			return ;
		}
		short mit = (a+b)/2 ;
		if( r<=mit )
			mete( r, g, pos*2+1, a, mit ) ;
		else
			mete( r, g, pos*2+2, mit+1, b ) ;
	}
};

struct blu {
	red carg[lim] ;
	int query( short P, short ini, short fin, short ini2, short fin2  ) {
		int res = 0 ;
		int tmp[lim] ;
		for( int i=0, W=0; i<lim; i++ ) {
			tmp[i] = carg[i].query(ini,fin,0,0,lim-1,ini2,fin2) ;
			W += tmp[i] ;
			if( i-P-1>=0 )
				W -= tmp[i-P-1] ;
			//if( P==2 )
				//printf("%d ", tmp[i] ) ;
			res = max( res,  W ) ;
		}
		//if( P==2 )
		//printf(" -> %d -> %d %d\n", res, ini, ini2 ) ;
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
			int tmp = segm.query(P, i, i+P, j, j+P ) ;
			//cout << P << " " << tmp << " " << K << endl ;
			if( tmp >= K  )  {
				//cout << "Hiar" << endl ;
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
	int x, y, z, w ;
	
	scanf("%d%d", &N,&K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d%d", &r[i], &g[i], &b[i] ) ;
		segm.mete( b[i], r[i], g[i] ) ;
		//segm.mete( i, i, 3, 0, 0, lim-1 ) ;
	}
	
	//cout << "Hiar" << endl ;
	ini = 0, fin=lim-1; 
	while( ini<fin ) {
		piv = (ini+fin)/2 ;
		//printf("->%d %d %d\n", ini, fin, piv ) ;
		if( sePuede(piv,K,x,y,z) )
			fin = piv ;
		else
			ini = piv+1 ;
	}
	
	sePuede(ini,K,x,y,z) ;
	if( 1 ) {
		int tmp[lim] ;
		for( int i=0, W=0; i<lim; i++ ) {
			tmp[i] = segm.carg[i].query(x,x+z,0,0,lim-1,y,y+z) ;
			W += tmp[i] ;
			if( i-z-1>=0 )
				W -= tmp[i-z-1] ;
			if( W>=K ) {
				w = max( 0, i-z ) ;
				break ;
			}
		}
	}
	
	printf("%d\n", ini ) ;
	for( int i=0; i<N && K>=0; i++ ) {
		if( r[i]>=x && r[i]<=x+z && g[i]>=y && g[i]<=y+z && b[i]>=w && b[i]<=w+z ) {
			K -- ;
			printf("%d %d %d\n", r[i], g[i], b[i] ) ;
		}
	}
	
	return 0 ;
}

