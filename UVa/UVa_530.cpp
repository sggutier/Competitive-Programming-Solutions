#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a, b ;

    while( scanf("%d%d", &a, &b)!=EOF && (a||b) ) {
	long long res = 1LL ;
	b = max( b, a-b ) ;
	for( int i=1; a-i+1>b; i++ )
	    res = res*(a-i+1)/i ;
	printf("%lld\n", res ) ;
    }
    
    return 0 ;
}
