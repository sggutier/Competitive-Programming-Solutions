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

void caso( int A, int B ) {
    for( int i=1; i<=A; i++ ) {
	long long x=A, y=B ;

	while( x%(i+1)==0 and y%i==0 ) {
	    x /= (i+1) ;
	    y /= i ;
	}

	if( x!=1 or y!=1 )
	    continue ;

	long long resA=0LL, resB=0LL ;
	x = A ;
	while( x>1 ) {
	    resA += y ;
	    resB += x*y ;
	    x /= i+1 ;
	    y *= i ;
	}
	resB += B ;

	printf("%lld %lld\n", resA, resB ) ;
	return ;
    }

    return ;
}

int main() {
    int A, B ;

    while( scanf("%d%d", &A, &B)!=EOF  and  (A or B ) )
	caso( A, B ) ;
    
    return 0 ;
}
