#include <cstdio>
#include <algorithm>
#include <list>
#include <iostream>
#include <cstring>
using namespace std ;
const int lim = 100005 ;

int main() {
    int N ;
    char S[lim] ;
    list <char> res ;
    list <char>::iterator it=res.begin() ;

    gets(S) ;
    N = strlen(S) ;

    for( int i=0; i<N; i++ ) {
        if( S[i]=='[' ) {
            it = res.begin() ;
            continue ;
        }
        else if( S[i]==']' ) {
            it = res.end() ;
            continue ;
        }
        res.insert( it, S[i] ) ;
    }

    for( it=res.begin(); it!=res.end(); it++ )
        printf("%c", *it ) ;
    printf("\n" ) ;

    return 0 ;
}
