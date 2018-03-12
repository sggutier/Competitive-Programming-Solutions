#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

bool usd[4000] ;

void caso() {
    int D, N, tmp ;
    scanf("%d%d", &D, &N ) ;
    memset( usd, 0, sizeof(usd) ) ;
    for( int i=0; i<N; i++ ) {
	scanf("%d", &tmp ) ;
	for( int j=tmp; j<=D; j+=tmp )
	    usd[j] = 1 ;
    }

    tmp = 0 ;
    for( int i=1; i<=D; i+=7 ) {
	for( int j=0; j<5 && i+j<=D; j++ ) 
	    if( usd[i+j] ) 
		tmp ++ ;
    }

    printf("%d\n", tmp );
}

int main(){
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
