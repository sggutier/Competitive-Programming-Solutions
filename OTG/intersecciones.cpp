#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define limC 1000005
#define limN 100000
#define par pair<int,int>
#define par2 pair< par,par > 
#define x first
#define y second


par in[limN] ;
par out[limN] ;
par2 ver[limN] ;
int bit[limC] ;
void upd( int i, int carg ) ;
int query( int pos ) ;

int main() {
	int N, V=0, H=0 ;
	int i, j, k ;
	long long res = 0LL ;
	par a, b ;
	
	scanf("%d",&N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d%d",&a.x,&a.y ) ;
		scanf("%d%d",&b.x,&b.y ) ;
		a.x ++ ;
		a.y ++ ;
		b.x ++ ;
		b.y ++ ;
		if( a > b )
			swap( a,b ) ;
		if( a.x == b.x )  {
			ver[V++] = par2( a,b ) ;
		}
		else {
			in[H] = a ;
			out[H] = b ;
			H ++ ;
		}
	}
	
	sort( ver, ver+V ) ;
	sort( in, in+H ) ;
	sort( out, out+H ) ;
	for( i=0, j=0, k=0; i<V; i++ ) {
		for( ; j<H && in[j].x<=ver[i].x.x; j++ ) 
			upd( in[j].y, 1 ) ;
		for( ; k<H && out[k].x<ver[i].x.x; k++ ) 
			upd( out[k].y, -1 ) ;
		res += query( ver[i].y.y ) - query( ver[i].x.y-1  )  ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}

void upd( int i, int carg ) {
	for( ; i<limC; i += (i&-i)  )  {
		bit[i] += carg ;
	}
}

int query( int pos ) {
	int res = 0 ;
	for( ; pos>0; pos -= (pos&-pos)  )  {
		res += bit[pos] ;
	}
	return res ;
}

