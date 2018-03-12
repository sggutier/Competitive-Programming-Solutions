#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <utility>
#include <set>
using namespace std ;
#define lim 1005
#define par pair<int,int>
#define x first
#define y second

struct choque {
	int a, b, t ;
	choque() {
	}
	choque( int p, int q, int r ) {
		a = p ;
		b = q ;
		t = r ;
	}
};

bool compChoque( choque A, choque B ) {
	return A.t < B.t ;
}

int dr[] = { 0, -1, 0, 1 } ;
int dc[] = { 1, 0, -1, 0 } ;
int R, C ;
int N, W=0 ;
int x[lim], y[lim], d[lim], res[lim] ;
bool usd[lim] ;
choque cruc[lim*lim] ;
map < int,  set< par >  >  hor, vert  ;
int lH=0, lV=0 ;
choque linH[lim], linV[lim] ;

int main() {
	scanf("%d%d", &R, &C) ;
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d%d", &y[i], &x[i], &d[i] ) ;
		for( int j=0; j<i; j++ ) {
			if( d[j] == d[i] )
				continue ;
			if( d[j] == (d[i]+2)%4  ) {
				if( dr[ d[i] ] ) {
					if( y[i] == y[j]  &&  (x[j]-x[i])/abs(x[j]-x[i]) == dr[ d[i] ]  )   {
						cruc[W++] = choque( i, j, abs(x[j]-x[i])   )  ;
					}
				}
				else {
					if( x[i] == x[j]  &&  (y[j]-y[i])/abs(y[j]-y[i]) == dc[ d[i] ]  )   {
						cruc[W++] = choque( i, j, abs(y[j]-y[i])   )  ;
					}
				}
			}
			else if( abs(y[i]-y[j]) == abs(x[i]-x[j])  ){
				if( dr[ d[i] ] ) {
					if(   (y[i]-y[j])/abs(y[i]-y[j]) == dc[ d[j] ]    &&  (x[j]-x[i])/abs(x[j]-x[i]) == dr[ d[i] ]  )   {
						cruc[W++] = choque( i, j, abs(y[j]-y[i])   )  ;
					}
				}
				else {
					if( (x[i]-x[j])/abs(x[i]-x[j]) == dr[ d[j] ]    &&  (y[j]-y[i])/abs(y[j]-y[i]) == dc[ d[i] ]  )   {
						cruc[W++] = choque( i, j, abs(y[j]-y[i])   )  ;
					}
				}
			}
		}
	}
	
	sort( cruc, cruc+W, compChoque ) ;
	for( int i=0; i<W; i++ ) {
		int j ;
		for( j=i; j<W && cruc[j].t==cruc[i].t; j++ ) {
			if( usd[ cruc[j].a ] || usd[ cruc[j].b ]  )
				continue ;
			res[ cruc[j].a ] = cruc[i].t ;
			res[ cruc[j].b ] = cruc[i].t ;
			usd[ cruc[j].a ] = 1 ;
			usd[ cruc[j].b ] = 1 ;
		}
		i = j-1 ;
	}
	for( int i=0; i<N; i++ ) {
		if( usd[i] )
			continue ;
		if( d[i]==0 )
			res[i] = C-y[i] ;
		if( d[i]==1 )
			res[i] = x[i]-1 ;
		if( d[i]==2 )
			res[i] = y[i]-1 ;
		if( d[i]==3 )
			res[i] = R-x[i] ;
	}
	
	set <par> tmp ;
	for( int i=0; i<N; i++ ) {
		par A, B ;
		A = par( x[i], y[i] ) ;
		B = par( x[i] + res[i]*dr[d[i]],   y[i] + res[i]*dc[d[i]]   ) ;
		if( A>B )
			swap( A, B ) ;
		if( A.x==B.x ) {
			if( hor.find(B.x) == hor.end()  )
				hor[B.x] = tmp ;
			hor[B.x].insert(  par(A.y,B.y)  ) ;
		}
		else {
			if( vert.find(B.y) == vert.end()  )
				vert[B.y] = tmp ;
			vert[B.y].insert(  par(A.x,B.x)  ) ;
		}
		printf("%d %d -> %d %d\n", A.x, A.y, B.x, B.y ) ;
	}
	printf("----\n" ) ;
	
	for( map < int,  set< par >  >::iterator it = hor.begin();  it!=hor.end();  it++   )   {
		int ult=-1, ult2=-1 ;
		for( set<par>::iterator it2= (it -> y).begin();  it2!=(it -> y).end();  it2++   )   {
			printf("->%d %d %d\n", it -> x, it2 -> x, it2 -> y ) ;
			if( ult==-1 ) {
				ult = (it2 -> y) ;
				ult2 = (it2 -> x ) ;
			}
			if( ult < (it2 -> y)  )
				linH[ lH++ ] = choque( it -> x, ult2, ult-ult2 ) ;
			else if( ult2 != (it2 -> x) )
				linH[ lH++ ] = choque( it -> x, ult2, (it2 -> x)-1 ) ;
			ult = max( ult, (it2 -> y) );
			ult2 = (it2 -> x) ;
		}
		if( ult!=-1 )
			linH[ lH++ ] = choque( it -> x, ult2, ult-ult2 ) ;
	}
	for( map < int,  set< par >  >::iterator it = vert.begin();  it!=vert.end();  it++   )   {
		int ult=-1, ult2=-1 ;
		for( set<par>::iterator it2= (it -> y).begin();  it2!=(it -> y).end();  it2++   )   {
			printf("-<%d %d %d\n", it2 -> x, it -> x, it2 -> y ) ;
			if( ult==-1 ) {
				ult = (it2 -> y) ;
				ult2 = (it2 -> x ) ;
			}
			if( ult < (it2 -> y)  )
				linV[ lV++ ] = choque( ult2, it -> x, ult-ult2 ) ;
			else if( ult2 != (it2 -> x) )
				linV[ lV++ ] = choque( ult2, it -> x, (it2 -> x)-1 ) ;
			ult = max( ult, (it2 -> y) );
			ult2 = (it2 -> x) ;
		}
		if( ult!=-1 )
			linV[ lV++ ] = choque( ult2, it -> x, ult-ult2 ) ;
	}
	
	for( int i=0; i<lH; i++ ) {		
		printf("%d %d %d\n", linH[i].a, linH[i].b, linH[i].t ) ;
	}
	printf("----\n" ) ;
	for( int i=0; i<lV; i++ ) {		
		printf("%d %d %d\n", linV[i].a, linV[i].b, linV[i].t ) ;
	}
	printf("----\n" ) ;
	
	return 0 ;
}
