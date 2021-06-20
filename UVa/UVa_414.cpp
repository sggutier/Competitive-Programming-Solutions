#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

void caso( int N ) {
    int res=0, tm=0;
    char tmp ;

    for( int i=0; i<N; i++ ) {
	int cnt = 0 ;
	scanf("%c", &tmp) ;
	for( int j=0; j<25; j++ ) {
	    scanf("%c",&tmp ) ;
	    if( tmp=='X' )
		cnt ++ ;
	}
	if( cnt>tm ) {
	    res += i*(cnt-tm) ;
	    tm = cnt ;
	}
	else
	    res += tm-cnt ;
    }
    printf("%d\n", res ) ;
}

int main() {
    int N ;
    while( scanf("%d",&N)!=EOF && N ) {
	caso(N ) ;
    }
    
    return 0 ;
}
