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

int gcd( int a, int b ) {
    int c ;

    while( b ) {
	c = b ;
	b = a%b ;
	a = c ;
    }

    return a ;
}

void caso( int N ) {
    int cnt = 0 ;
    int arr[lim] ;

    for( int i=0; i<N; i++ ) {
	scanf("%d", &arr[i] ) ;
	for( int j=0; j<i; j++ )
	    if( gcd(arr[i],arr[j])==1 )
		cnt ++ ;
    }

    if( cnt==0 )
	printf("No estimate for this data set.\n" ) ;
    else
	printf("%.6lf\n", sqrt( (6.0*  (N*(N-1))/2  )/cnt ) ) ;
}

int main() {
    int N ;

    while( scanf("%d",&N)!=EOF  and N )
	caso(N) ;
    
    return 0 ;
}
