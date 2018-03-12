#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
    int A, B, C, w ;

    for( scanf("%d",&A); A; A-- ) {
        w = 0 ;
        for( scanf("%d",&B); B; B-- ) {
            scanf("%d", &C ) ;
            if( w )
                printf(" " ) ;
            w = 1 ;
            printf("%d", C*2 ) ;
        }
        printf("\n" ) ;
    }

    return 0 ;
}
