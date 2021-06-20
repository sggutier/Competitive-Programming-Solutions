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
const int lim = 15 ;

int main() {
    int T, N ;
    char S[lim] ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	scanf("%s", S ) ;
	N = strlen(S) ;

	sort( S, S+N ) ;
	do {
	    printf("%s\n", S ) ;
	} while( next_permutation(S,S+N) ) ;
	printf("\n" ) ;
    }
    
    return 0 ;
}
