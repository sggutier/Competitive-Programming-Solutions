#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;

void caso( int N ) {
    printf("TERM %d IS ", N ) ;
    int ren = int( (-1+sqrt(8*N))/2 ) +1, col ;

    N -= ren*(ren-1)/2 ;

    if( ren%2 ) {
	col = N ;
	ren -= N-1 ;
    }
    else {
	col = ren+1-N ;
	ren = N ;
    }

    printf("%d/%d\n", ren, col ) ;
}

int main() {
    int N ;
    while( scanf("%d", &N) != EOF )
	caso(N) ;
    
    return 0 ;
}
