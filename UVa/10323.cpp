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
const long long mucho = 6227020800LL ;
const long long poco = 10000LL ;

long long calc( int N ) {
    if( N<0 ) 
	return (N%2)? mucho+1 : poco-1 ;
    long long res = 1 ;
    for( int i=1; i<=N and res<=mucho; i++ )
	res = res*i ;
    return res ;
}

int main() {
    int N ;

    while( scanf("%d",&N)!=EOF ) {
	long long tmp = calc(N) ;

	if( tmp<poco )
	    printf("Underflow!\n" ) ;
	else if( tmp>mucho )
	    printf("Overflow!\n" ) ;
	else
	    printf("%lld\n", tmp ) ;
    }
    
    return 0 ;
}
