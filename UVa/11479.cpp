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

void caso() {
    long long arr[3] ;

    scanf("%lld%lld%lld", &arr[0], &arr[1], &arr[2] ) ;

    sort( arr, arr+3 ) ;

    if( arr[0]<=0 or arr[0] + arr[1] <= arr[2] )
	printf("Invalid\n" ) ;
    else if( arr[0]==arr[1] and arr[1]==arr[2] )
	printf("Equilateral\n" ) ;
    else if( arr[0]==arr[1] or arr[1]==arr[2] )
	printf("Isosceles\n" ) ;
    else
	printf("Scalene\n" ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	printf("Case %d: ", i+1 ) ;
	caso() ;
    }
    
    return 0 ;
}
