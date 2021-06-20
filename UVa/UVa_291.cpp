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

int gr[][6] = { { 0, 1, 1, 0, 1 },
	       { 1, 0, 1, 0, 1 },
	       { 1, 1, 0, 1, 1 },
	       { 0, 0, 1, 0, 1 },
	       { 1, 1, 1, 1, 0 } } ;

bool vald( char arr[8] )  {
    int N = 8, pos=0 ;
    int cpy[6][6] ;

    for( int i=0; i<6; i++ ) 
	for( int j=0; j<6; j++ )
	    cpy[i][j] = gr[i][j] ;
    
    for( int i=0; i<N; i++  ) {
	if( !cpy[pos][ arr[i]-'1' ] )
	    return false ;
	cpy[pos][ arr[i]-'1'] = 0 ;
	cpy[ arr[i]-'1'][pos] = 0 ;
	pos = arr[i]-'1' ;
    }

    return true ;
}
	       

int main() {
    char S[] = "12233455" ;
    //char S[] = "53125432" ;

    do {
	if( vald(S) )
	    printf("1%s\n", S ) ;
    } while( next_permutation(S, S+8) ) ;
    
    return 0 ;
}
