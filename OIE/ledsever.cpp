#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;

int main() {
    char S[1000] ;

    while( scanf("%s",S) != EOF ) {
        reverse( S, S+strlen(S) ) ;
        printf("%s\n", S ) ;
    }

    return 0 ;
}
