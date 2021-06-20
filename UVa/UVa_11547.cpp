#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int T, N ;

    scanf("%d", &T ) ;
    for( ; T; T-- ) {
	scanf("%d", &N ) ;
	printf("%d\n", abs((N*63+7492)*5-498)/10%10 ) ;
    }
    
    return 0 ;
}
