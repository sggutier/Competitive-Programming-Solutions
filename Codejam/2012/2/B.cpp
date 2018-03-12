#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
#define par pair<double,double>
#define x first
#define y second

int N, W ;
int tam[20] ;
par pos[20] ;
int X, Y ;

bool intersec( double a, double b, double c, double d ) {
	return  ( c>a && c<b ) || ( a>c && a<d ) || ( d>a && d<b ) || ( b>c && b<d ) || c==a || b==d ;
	//return  ( c>=a && c<=b ) || ( a>=c && a<=d ) ;
}

bool sePuede( double x, double y ) {
	if( y > Y )
		return 0 ;
	for( int i=0; i<W; i++ ) {
		if( intersec( x-tam[W], x+tam[W], pos[i].x-tam[i], pos[i].x+tam[i] )    &&   intersec( y-tam[W], y+tam[W], pos[i].y-tam[i], pos[i].y+tam[i] )   )
			x = max( x, pos[i].x+tam[i]+tam[W] ) ;
	}
	if( x > X )
		return 0 ;
	pos[W] = par( x, y ) ;
	return 1 ;
}

void caso() {
	scanf("%d%d%d", &N, &X, &Y ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &tam[i] ) ;
	
	W = 0 ;
	sort( tam, tam+N ) ;
	do {
		W = 1 ;
		pos[0] = par( 1.0*0, 1.0*0 ) ;
		for( W=1; W<N; W++ ) {
			bool lug = 0 ;
			par menPos = par( (1<<30)*1.0, (1<<30)*1.0 ) ;
			if( sePuede( 0*1.0, 0*1.0 )  ) 
				lug = 1 ;
			for( int i=0; i<W && !lug; i++ ) {
				if( sePuede( 0*1.0, pos[i].y+tam[i]+tam[W] )  )  {
					lug = 1 ;
				}
			}
			if( !lug )
				break ;
		}
		/*for( int i=0; i<N; i++ ) {
			printf("%0.2lf %0.2lf\n", pos[i].x, pos[i].y ) ;
		}
		if( W!=N )
			cout << tam[W] << endl ;
		else
			cout << endl ;
		getchar() ;*/
		if( W==N ) {
			for( int i=0; i<N; i++ ) {
				printf("%0.2lf %0.2lf ", pos[i].x, pos[i].y ) ;
			}
			printf("\n" ) ;
			return ;
		}
	}while( next_permutation( tam, tam+N) ) ;
}

int main() {
	int T ;
	
	scanf("%d", &T ) ;
	for( int i=1; i<=T; i++ )  {
		printf("Case #%d: ", i ) ;
		caso() ;
	}
}
