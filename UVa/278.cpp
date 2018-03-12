#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;

int king( int R, int C ) {
    return int(ceil(R/2.0))*int(ceil(C/2.0)) ;
}

int rook( int R, int C ) {
    return min( R, C ) ;
}

int knight( int R, int C ) {
    return max( int(floor(R/2.0))*C + (R%2)*int(ceil(C/2.0)),
		int(floor(C/2.0))*R + (C%2)*int(ceil(R/2.0)) ) ;
}

int queen( int R, int C ) {
    return min( R, C ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	int a, b ;
	char S[5] ;
	scanf("%s%d%d", S, &a, &b ) ;
	switch(S[0]) {
	case 'r':
	    a = rook(a,b) ;
	    break ;
	case 'k':
	    a = knight(a,b) ;
	    break ;
	case 'Q':
	    a = queen(a,b) ;
	    break ;
	case 'K' :
	    a = king(a,b) ;
	    break ;
	}
	printf("%d\n", a ) ;
    }
    
    return 0 ;
}
