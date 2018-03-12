#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef pair<ld,ld> par ;
#define f first
#define s second


struct rect {
	ld a, b, c ;
	rect() {
	}
	rect( par F, par S ) {
		a = y2-y1 ;
		b = x1-x2 ;
		c = A*x1+B*y1 ;
	}
};


int area( par A, par B, par C ) {
	ld res = (0LL)*1.0 ;
	
	res += A.x * B.y ;
	res += B.x * C.y ;
	res += C.x * A.y ;
	res -= A.y * B.x ;
	res -= B.y * C.x ;
	res -= C.y * A.x ;
	
	return res ;
}


void caso() {
	par arr[3][2] ;
	int i, j ;
	ll a, b ;
	
	for( i=0; i<3; i++ ) {
		for( j=0; j<2; j++ ) {
			scanf("%d", &a ) ;
			arr[i][j] = (a+0LL)*1.0 ;
		}
	}
	
	for( i=0; i<2; i++ ) {
		for( j=i+1; j<3; j++ ) {
			a = area( arr[i][0], arr[i][1], arr[j][0] ) ;
			b = area( arr[i][0], arr[i][1], arr[j][1] ) ;
			
			a = a/abs(a) ;
			b = b/abs(b) ;
			
			if( a==b ) {
				printf("NO\n" ) ;
				return ;
			}
		}
	}
	
	printf("NO\n" ) ;
}

int main() {
	return 0 ;
}
