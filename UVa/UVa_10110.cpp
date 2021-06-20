#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std ;

int main() {
    unsigned int N ;

    while( scanf("%u", &N ) && N ) {
	unsigned rt = int( sqrt(N) ) ;
	printf("%s\n", rt*rt==N? "yes" : "no" ) ;
    }
    
    return 0 ;
}
