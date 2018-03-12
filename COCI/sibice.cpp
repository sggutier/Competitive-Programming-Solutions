#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
    int N, X, Y ;
    int W ;

    scanf("%d%d%d", &N, &X, &Y ) ;
    for( int i=0; i<N; i++ ) {
        scanf("%d", &W ) ;
        cout <<  ((W*W <= X*X + Y*Y)? "DA" : "NE") << endl ;
    }

    return 0 ;
}
