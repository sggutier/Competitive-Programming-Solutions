#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int f91( int N ) {
    if( N>=101 )
	return N-10 ;
    return f91( f91(N+11) ) ;
}

int main() {
    int N ;

    while( scanf("%d", &N) && N )
	printf("f91(%d) = %d\n", N, f91(N) ) ;
    
    return 0 ;
}
