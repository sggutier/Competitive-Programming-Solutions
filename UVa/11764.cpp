#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

void caso() {
    int resA=-1, resB=0, N, ult=-1e9, act ;
    scanf("%d", &N ) ;
    for( ; N; N-- ) {
	scanf("%d", &act ) ;
	if( act>ult )
	    resA ++ ;
	else if( act<ult )
	    resB ++ ;
	ult = act ;
    }
    printf("%d %d\n", resA, resB ) ;
}
	

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	printf("Case %d: ", i+1 ) ;
	caso() ;
    }
    
    return 0 ;
}
