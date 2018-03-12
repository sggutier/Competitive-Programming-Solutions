#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int N ;
    double sum = 1.0*0 ;

    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ ) {
        int a ;
        scanf("%d", &a ) ;
        sum += a ;
    }

    printf("%0.9lf\n", sum/N ) ;

    return 0 ;
}
