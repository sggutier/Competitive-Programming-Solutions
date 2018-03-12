#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    long long A, B ;

    while( scanf("%lld%lld", &A, &B ) != EOF ) {
	printf("%lld\n", abs(A-B) ) ;
    }
    
    return 0 ;
}
