#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    double prom = 1.0*0, tmp ;

    for( int i=0; i<12; i++ )  {
        scanf("%lf", &tmp ) ;
        prom += tmp ;
    }

    printf("$%0.2lf\n", prom/12.0 ) ;

    return 0 ;
}
