#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
    int A, B, C ;
    int x, y, z ;

    scanf("%d:%d:%d", &x, &y, &z ) ;
    A = x*3600 + y*60 + z ;
    scanf("%d:%d:%d", &x, &y, &z ) ;
    B = x*3600 + y*60 + z ;

    C = (86400*2 + B-A ) % 86400 ;
    if( C==0 )
        C = 86400 ;

    printf("%02d:%02d:%02d\n", C/3600, (C/60)%60, C%60 ) ;

    return 0 ;
}
