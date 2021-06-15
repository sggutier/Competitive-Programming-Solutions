#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second

int mcd( int a, int b ) {
	int c ;
	while( b ) {
		c = b ;
		b = a%b ;
		a = c ;
	}
	return c ;
}

int main() {
	int n, v, m ;
	int d, a, b, q ;
	int i, j, pos ;
	
	scanf("%d%d%d", &n, &v, &m ) ;
	
	i = mcd( n, m ) ;
	d = m/i ;
	a = n/i ;
	q = a/d ;
	a %= d ;
	
	if( n<m ) {	
		b = 0 ;		
		for( i=0; i<m && b<=a; i++ ) {
			b = (   d - (a-b+d)%d  ) %d ;
		}
		
		if( i!=m ) {
			printf("NO\n" ) ;
			return 0 ;
		}
	}
	
	printf("YES\n" ) ;	
	b = 0 ;
	pos = 0 ;
	for( i=0; i<m; i++ ) {		
		if( b!=0 ) {
			printf("%d ", pos ) ;
			printf("%0.9lf ", ( b/(d*1.0) )*v   )   ;
		}
		
		if( b>a ) 
			j = 1 ;
		else
			j = 0 ;
			
		for( ; j<q; j++ ) {
			printf("%d ", ++pos ) ;
			printf("%0.9lf ", 1.0*v   )   ;
		}
		
		if(  (a-b+d)%d   ) {
			printf("%d ", ++pos ) ;
			printf("%0.9lf ", (  ((a-b+d)%d)/(d*1.0)   )*v   )   ;
		}
		
		printf("\n" ) ;
		
		b = (   d - (a-b+d)%d  ) %d ;
	}
	
	return 0 ;
}
