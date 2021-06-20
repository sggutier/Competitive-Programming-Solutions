#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;

void t_case( int N ) {
    int K = int(ceil(N/4.0)) ;
    int res[200][2] ;

    memset( res, 0, sizeof(res) ) ;

    for( int i=1, pos=0, lad=1, dir=1; i<=N; i++, pos+=dir, lad=1-lad ) {
	if( pos>=2*K ) {
	    pos = 2*K-1 ;
	    dir *= -1 ;
	}
	res[pos][lad] = i ;
    }

    printf("Printing order for %d pages:\n", N ) ;
    for( int i=0; i<2*K; i++ ) {
	if( !res[i][0] && !res[i][1] )
	    continue ;
	printf("Sheet %d, %s: ", i/2+1, (i%2)? "back " : "front" ) ;
	if( res[i][0] )
	    printf("%d, ", res[i][0]) ;
	else
	    printf("%s, ", "Blank" ) ;
	if( res[i][1] )
	    printf("%d\n", res[i][1]) ;
	else
	    printf("%s\n", "Blank" ) ;
    }
}

int main() {
    int N ;
    while( scanf("%d", &N) && N  )
	t_case(N ) ;
    
    return 0 ;
}
