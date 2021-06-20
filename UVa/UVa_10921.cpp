#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>
using namespace std ;

int rep[256] ;
string S[9] = { "1---",
	       "ABC-",
	       "DEF-", 
	       "GHI-",
	       "JKL-",
	       "MNO-",
	       "PQRS",
	       "TUV-",
	       "WXYZ" } ;

int main() {
    for( int i=0; i<9; i++ )
	for( int j=0; j<4; j++ )
	    rep[S[i][j]] = i+'1' ;
    rep['-'] = '-' ;
    rep['\n'] = '\n' ;
    rep['0'] = '0' ;

    char tmp ;
    while( scanf("%c",&tmp)!=EOF ) {
	printf("%c", rep[tmp] ) ;
    }

    
    return 0 ;
}
