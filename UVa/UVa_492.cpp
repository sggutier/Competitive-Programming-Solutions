#include <cstdio>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std ;
const int lim = 100005 ;

int N ;
char S[lim] ;

void caso() {
    bool pto = 0, prt=0 ;
    int ini = 0 ;
    set <int> vcs ;

    if( S[N-1]=='.' ) {
	N -- ;
	pto = 1 ;
    }

    vcs.insert( 'a' ) ;
    vcs.insert( 'e' ) ;
    vcs.insert( 'i' ) ;
    vcs.insert( 'o' ) ;
    vcs.insert( 'u' ) ;

    if( isalpha(S[0]) ) {
	if(  vcs.find(tolower(S[0]))==vcs.end()  )
	    ini ++ ;		
	prt = 1 ;
    }

    for( int i=ini; i<N; i++ )
	printf("%c", S[i] ) ;
    if( ini )
	printf("%c", S[0] ) ;
    if( prt )
	printf("ay" ) ;
}

int main() {
    char c, ant=' '  ;
    
    while( scanf("%c",&c) != EOF  ) {
	if(  !isalpha(c) ) {
	    if( N ) {
		caso() ;
		N = 0 ;
	    }
	    printf("%c", c ) ;
	}
	else
	    S[N++] = c ;
    }
    if( N ) {
	caso() ;
	printf("\n" ) ;
    }
    
    return 0 ;
}
