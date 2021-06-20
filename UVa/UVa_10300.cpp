#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

void caso() {
    int N ;
    int a, b, c ;
    int res = 0 ;
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
	scanf("%d%d%d", &a, &b, &c ) ;
	res += a*c ;
    }
    printf("%d\n", res ) ;
}
    
int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
