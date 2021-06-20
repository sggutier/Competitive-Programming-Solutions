#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

void t_case( int N, int P, int H, int W  ) {
    int res = (1<<30) ;
    for( int i=0; i<H; i++ ) {
	int cst, tmp ;
	scanf("%d", &cst ) ;
	for( int j=0; j<W; j++ ) {
	    scanf("%d", &tmp ) ;
	    if( tmp>=N )
		res = min( res, cst*N ) ;
	}
    }
    if( res>P )
	printf("stay home\n" ) ;
    else
	printf("%d\n", res ) ;
}

int main() {
    int P, B, H, W ;

    while( scanf("%d%d%d%d", &B, &P, &H, &W ) != EOF )
	t_case( B, P, H, W ) ;
    
    return 0 ;
}
