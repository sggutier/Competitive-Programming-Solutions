#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define x first
#define y second
#define lim 100005

int dis( par A, par B ) {
	return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) ;
}

int area( par A, par B, par C ) {
	int res = 0 ;
	res += A.x * B.y ;
	res += B.x * C.y ;
	res += C.x * A.y ;
	res -= A.y * B.x ;
	res -= B.y * C.x ;
	res -= C.y * A.x ;
	if( res==0 )
		return 0 ;
	return res / abs(res) ;
}

int N ;
par pts[lim] ;
bool usd[lim] ;

int procA( int A, int B ) {
	for( int i=0; i<N; i++ ) {
		if( i==A || i==B )
			continue ;
			
		if( dis(pts[A],pts[i]) == dis(pts[B],pts[i])   )
			continue ;
		int j ;
		for( j=0; j<N; j++ ) {
			if( j==i || j==A || j==B )
				continue ;
			if( dis(pts[A],pts[i]) == dis(pts[B],pts[j]) && dis(pts[B],pts[i]) == dis(pts[A],pts[j])   ) {
				if( area( pts[i], pts[A], pts[B] ) == area( pts[j], pts[A], pts[B] )  )  {
					break ;
				}
			}
		}
		if( j==N )
			return 0 ;
	}
	
	return 1 ;
}

int procB( int A, int B ) {
	
	for( int i=0; i<N; i++ ) {
		if( i==A || i==B )
			continue ;
		if( area(pts[A],pts[B],pts[i]) == 0  ) {
			usd[i] = 1 ;
			continue ;
		}
			
		int j ;
		for( j=0; j<N; j++ ) {
			if( j==i || j==A || j==B )
				continue ;
			if( dis(pts[A],pts[i]) == dis(pts[A],pts[j]) && dis(pts[B],pts[i]) == dis(pts[B],pts[j])   )
				break ;
		}
		if( j==N )
			return 0 ;
	}
	
	return 1 ;
}

int main() {
	freopen( "symmetry.in", "r", stdin ) ;
	freopen( "symmetry.out", "w", stdout ) ;
	
	int res = 0 ;
	
	scanf("%d", &N) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d%d", &pts[i].x, &pts[i].y ) ;
		
	for( int i=1; i<N; i++ ) {
		res += procA( 0, i ) ;
		if( !usd[i] ) {
			res += procB( 0, i ) ;
		}
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}

