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

set <string> res ;

int main() {
    char S[lim] ;
    int N=0 ;

    memset( S, 0, sizeof(S) ) ;

    while( scanf("%c",&S[N])!=EOF ) {
	N ++ ;
	S[N-1] = tolower( S[N-1] ) ;
	if( isalpha(S[N-1]) )
	    continue ;
	S[N-1] = 0 ;
	if( N>1 ) 
	    res.insert(S) ;
	for( ; N>=0; N-- )
	    S[N] = 0 ;
	N = 0 ;
    }
    if( N>=1 and isalpha(S[N-1]) )
	res.insert(S) ;

    for( set <string>::iterator it=res.begin(); it!=res.end(); it++ )
	printf("%s\n", (*it).c_str() ) ;
    
    return 0 ;
}
