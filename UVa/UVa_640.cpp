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
const int lim = 1e6 +1 ;

bool usd[lim] ;

int sig( int N ) {
    int res = N ;
    while( N ) {
	res += N%10 ;
	//res /= 10 ;
	N /= 10 ;
    }
    return res ;
}

int main() {
    for( int i=1; i<lim; i++ ) {
	int tmp = sig(i) ;
	if( tmp<lim )
	    usd[tmp] = 1 ;
    }

    for( int i=1; i<lim; i++ )  {
	if( !usd[i] ) {
	    printf("%d\n", i ) ;
	    //getchar() ;
	}
    }
    
    return 0 ;
}
