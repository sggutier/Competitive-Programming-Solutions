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

int N ;
char S[lim] ;

int main() {
    while( fgets( S, lim, stdin ) ) {
	N = strlen(S)-1 ;
	S[N] = 0 ;
	if( N==4 and  strcmp(S,"DONE")==0 )
	    break ;
	char arr[lim] ;
	int A=0 ;
	bool res = 1 ;

	for( int i=0; i<N; i++ )
	    if( isalpha(S[i]) )
		arr[A++] = tolower(S[i]) ;

	for( int i=A/2-1; i>=0; i-- ) {
	    if( arr[A-1-i]!=arr[i] ) {
		res = 0 ;
		break ;
	    }
	}

	printf("%s\n", res? "You won't be eaten!" : "Uh oh.." ) ;	       
    }
    
    return 0 ;
}
