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

int fA[lim] ;

void caso( int N, int Q ) {
    int arr[lim] ;

    for( int i=0; i<N; i++ )
	scanf("%d", &arr[i] ) ;
    sort( arr, arr+N ) ;
    memset( fA, 0, sizeof(fA)  ) ;

    for( int i=0; i<N; i++ )
	if( !i or arr[i]!=arr[i-1] )
	    fA[ arr[i] ] = i+1 ;

    for( int i=0; i<Q; i++ ) {
	int a ;
	scanf("%d", &a ) ;
	if( fA[a] )
	    printf("%d found at %d\n", a, fA[a] ) ;
	else
	    printf("%d not found\n", a ) ;
    }
}

int main() {
    int T=1 ;
    int A, B ;

    while( scanf("%d%d", &A, &B)!=EOF and (A or B)  ) {
	printf("CASE# %d:\n", T++ ) ;
	caso( A, B ) ;
    }
    
    return 0 ;
}
