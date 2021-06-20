#include <cstdio>
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
#include <cctype>
using namespace std ;
#define par pair< int, int >
#define p1 first
#define p2 second
const int lim = 100005 ;

void caso() {
    char S[lim] ;
    int N ;

    scanf("%s", S ) ;
    N = strlen(S) ;

    for( int i=0; i<N; i++ ) {
	if( isupper(S[i]) )
	    S[i] = (S[i]-'A') *2 ;
	else
	    S[i] = (S[i]-'a')*2 +1 ;
    }

    sort( S, S+N );
    do {
	for( int i=0; i<N; i++ )
	    printf("%c", S[i]%2? (S[i]-1)/2 + 'a': S[i]/2 + 'A' ) ;
	printf("\n" ) ;
    } while( next_permutation( S, S+N ) ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}
