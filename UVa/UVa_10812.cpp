#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int N ;
    int a, b ;

    scanf("%d", &N );
    for( int i=0; i<N; i++ ){
	scanf("%d%d", &a, &b ) ;
	int x, y ;
	if( (a+b)%2 ) {
	    printf("impossible\n" ) ;
	    continue ;
	}
	x = (a+b)/2 ;
	y = a-x ;
	if( x<y )
	    swap( x, y ) ;
	if( y<0 )
	    printf("impossible\n" ) ;
	else
	    printf("%d %d\n", x, y ) ;
    }
    
    return 0 ;
}

19
19
rrna
4
7
5
