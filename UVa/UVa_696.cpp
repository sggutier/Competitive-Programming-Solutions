#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;

int knight( int R, int C ) {
    if( R==1 || C==1 ) {
	return R*C ;
    }
    if( R==2 || C==2 ) {
	if( R<C )
	    swap( R, C ) ;
	return int(floor(R/4.0)*2 + min(R%4,2) )*2 ;
    }
    return max( int(floor(R/2.0))*C + (R%2)*int(ceil(C/2.0)),
		int(floor(C/2.0))*R + (C%2)*int(ceil(R/2.0)) ) ;
}

int main() {
    int a, b ;
    while( scanf("%d%d", &a,&b) && a && b ) {
	printf("%d knights may be placed on a %d row %d column board.\n", knight(a,b), a, b  ) ;
    }
    return 0 ;
}
