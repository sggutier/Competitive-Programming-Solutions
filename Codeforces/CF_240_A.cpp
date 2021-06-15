#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;
const int lim = 105 ;

struct ord {
	int x, y, id ;
	ord() {
	}
	ord( int a, int b, int c ) {
		x = a ;
		y = b ;
		id = c ;
	}
};

bool operator<( ord A, ord B ) {
	if( A.x != B.x )
		return A.x < B.x ;
	return A.y < B.y ;
}


int A, F, Q ;
bool fav[lim] ;
int res[lim] ;


int main() {
	freopen( "input.txt", "r", stdin ) ;
	freopen( "output.txt", "w", stdout ) ;
	
	char dumbo[lim] ;
	ord arr[lim] ;
	
	scanf("%d%d", &A, &F ) ;
	for( int i=0; i<F; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		fav[tmp] = 1 ;
	}
	scanf("%d", &Q ) ;
	for( int i=0; i<Q; i++ ) {
		int N, k=0, w=0, z=0 ;
		
		scanf("%s", dumbo ) ;
		scanf("%d", &N ) ;
		
		for( int j=0; j<N; j++ ) {
			int tmp ;
			scanf("%d", &tmp ) ;
			if( fav[tmp] ) 
				w ++ ;
			else if( tmp==0 )
				k ++ ;
			else
				z ++ ;
		}
		z = A-z ;
		
		arr[i].id = i ;
		arr[i].y = w + min( k, F-w ) ;
		arr[i].x = w + max( 0, k-(z-F)  ) ;
	}
	
	/*for( int i=0; i<Q; i++ ) 
		cout << "-> " << arr[i].x << " " << arr[i].y << endl ;*/
	
	sort( arr, arr+Q ) ;
	for( int i=0; i<Q; i++ ) {
		
		int a=0, b=0, c=0 ;
		for( int j=0; j<Q; j++ ) {
			if( i==j )
				continue ;
			if( arr[i].y < arr[j].x )
				c ++ ;
			else if( arr[i].x >= arr[j].y )
				a ++ ;
			else
				b ++ ;
		}
		
		if( c>0 )
			res[ arr[i].id ] = 1 ;
		else if( b>0 )
			res[ arr[i].id ] = 2 ;
		else
			res[ arr[i].id ] = 0 ;
	}
	
	for( int i=0; i<Q; i++ )
		printf("%d\n", res[i] ) ;
	
	return 0 ;
}
