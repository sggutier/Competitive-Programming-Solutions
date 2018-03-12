#include <cstdio>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std ;
#define mod 1000000007LL
#define lim 40004

struct frnds{
	int padre[lim] ;
	frnds() {
		for( int i=0; i<lim; i++ )
			padre[i] = -1 ;
	}
	int raiz( int pos ) {
		if( padre[pos]==-1 )
			return pos ;
		return padre[pos]=raiz(padre[pos]) ;
	}
	void une( int A, int B ) {
		A = raiz(A) ;
		B = raiz(B) ;
		padre[B] = A ;
	}
	int raizT( int pos ) {
		while( padre[pos]!=-1 )
			pos = padre[pos] ;
		return pos ;
	}
	void uneT( int A, int B ) {
		A = raizT(A) ;
		B = raizT(B) ;
		padre[B] = A ;
	}
} ;

struct edg{
	int a, b, c ;
	edg() {
	}
	edg( int A, int B, int C ) {
		a = A ;
		b = B ;
		c = C ;
	}
};

bool operator<( edg A, edg B ) {
	return A.c < B.c ;
}

int N ;
edg arr[lim] ;
long long res=1LL ;
frnds red ;

int main() {
	int W, minSum ;
	int tam[5] ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c ) ;
	
	sort( arr, arr+N ) ;
	for( int i=0; i<N; i++ ) {
		if( i && arr[i].c==arr[i-1].c )	
			continue ;
			
		for( W=0; i+W<N && arr[W+i].c==arr[W+i-1].c; W++ ) 
			tam[W] = 0 ;
		tam[W] = 0 ;
		minSum = 0 ;
		for( int b=0; b<(1<<W); b++ ) {
			int j, e=0 ;
			int org[5] ;
			for( j=0; j<W; j++ ) {
				if( !((1<<j)&b)   )
					continue ;
			}
			for( j=0; j<W; j++ ) {
				if( !((1<<j)&b)   )
					continue ;
				if( red.raizT(arr[i+j].a) == red.raizT(arr[i+j].b)   )
					break ;
				red.une( arr[i+j].a, arr[i+j].b ) ;
				e ++ ;
			}
			if( j==W ) {
				tam[e] ++ ;
				j-- ;
			}
			for( ; j>=0; j-- ) {
				if( !((1<<j)&b)   )
					continue ;
				if( red.raizT(arr[i+j].a) == red.raizT(arr[i+j].b)   )
					break ;
				red.une( arr[i+j].a, arr[i+j].b ) ;
				e ++ ;
			}
		}
	}
	
	return 0 ;
}
