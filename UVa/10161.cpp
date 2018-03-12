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
using namespace std ;
const int lim = 100005 ;

int dr[] = { 0, -1, 1, 0 } ;
int dc[] = { 1, 0, 0, -1 } ;

void caso( int N ) {
    int d = 0, x=1, y=1 ;
    int p = 1, s=1 ;
    bool dbl = 0 ;

    while( p<N ) {
	if( x==1 and !dbl ) {
	    y ++ ;
	    p ++ ;
	    dbl = 1 ;
	}
	else if( y==1 and !dbl ) {
	    x ++ ;
	    p ++ ;
	    dbl = 1 ;
	}
	else {
	    dbl = 0 ;
	    if( s+p>=N ) {
		x += dc[d]*(N-p) ;
		y += dr[d]*(N-p) ;
		p = N ;
	    }
	    else {
		x += dc[d]*s ;
		y += dr[d]*s ;
		p += s ;
		if( d%2==1 )
		    s ++ ;
		d = (d+1)%4 ;
	    }
	}
    }

    printf("%d %d\n", x, y ) ;
}

int main() {
    int N ;

    while( scanf("%d",&N)!=EOF  and   N )
	caso(N) ;
    
    return 0 ;
}
