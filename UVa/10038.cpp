#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std ;

int N ;
bool usd[3005] ;

void caso() {
    int ult ;
    memset( usd, 0, sizeof(usd) ) ;
    
    for( int i=0; i<N; i++ ) {
	int tmp ;
	scanf("%d", &tmp) ;
	if( !i ) {
	    ult = tmp ;
	    continue ;
	}
	if( abs(tmp-ult)<N )
	    usd[abs(tmp-ult)] = 1 ;
	ult = tmp ;
    }
    for( int i=1; i<N; i++ ) {
	if( !usd[i] ) {
	    printf("Not jolly\n") ;
	    return ;
	    break ;
	}
    }
    printf("Jolly\n" ) ;
}

int main() {
    while( scanf("%d",&N) != EOF ) {
	caso() ;
    }
    
    return 0 ;
}
