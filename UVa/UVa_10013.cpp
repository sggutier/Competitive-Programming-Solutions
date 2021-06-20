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
const int lim = 1000005 ;

int N ;
int A[lim], B[lim], C[lim] ;

void suma() {
    int tmp = 0 ;
    
    for( int i=0; i<N; i++ ) {
	tmp += A[i]+B[i] ;
	C[i] = tmp%10 ;
	tmp /= 10 ;
    }
    if( tmp )
	C[N++] = tmp ;
}

void caso() {
    scanf("%d", &N ) ;
    for( int i=N-1; i>=0; i-- )
	scanf("%d%d", &A[i], &B[i] ) ;
    suma() ;
    for( int i=N-1; i>=0; i-- )
	printf("%d", C[i]) ;
    printf("\n" ) ;
}

int main() {
    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	if( i )
	    printf("\n" ) ;
	caso() ;
    }
    
    return 0 ;
}
