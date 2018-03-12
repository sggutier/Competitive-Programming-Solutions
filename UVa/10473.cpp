#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = 1e9 ;
const int lim = 1e5 + 5 ;

char S[lim] ;

int main() {
    while( fgets(S,lim,stdin) ) {
	int N = strlen(S)-1 ;
	int K ;
	if( S[0]=='-' )
	    break ;
	if( N<2 or S[1]!='x' ) {
	    sscanf( S, "%d", &K ) ;
	    printf("0x%X\n", abs(K) ) ;
	}
	else {
	    sscanf( S, "%x", &K ) ;
	    printf("%d\n", K ) ;
	}
    }
    
    return 0 ;
}
