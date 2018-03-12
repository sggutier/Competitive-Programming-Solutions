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
const int inf = (1<<30) ;
const int lim = 21 ;
const double eps = 1e-9 ;
const int dr[] = { -1, 0, 1, 0 } ;
const int dc[] = { 0, 1, 0, -1 } ;

void caso() {
    int a, b, c ;
    int A[lim], B[lim], C[lim] ;
    int N ;

    scanf("%d%d%d", &a, &b, &c ) ;
    scanf("%d", &N ) ;
    for( int i=0; i<N; i++ )
	scanf("%d%d%d", &A[i], &B[i], &C[i] ) ;

    for( int bt=0; bt<(1<<N); bt++ ) {
	int sumA=0, sumB=0, sumC=0 ;
	
	for( int i=0; i<N; i++ ) {
	    if( (1<<i)&bt ) {
		sumA += A[i] ;
		sumB += B[i] ;
		sumC += C[i] ;
	    }
	}

	if( sumA==a and sumB==b and sumC==c ) {
	    printf("yes\n" ) ;
	    return ;
	}
    }

    printf("no\n" ) ;
}

int main() {
    int N ;

    scanf("%d", &N ) ;
    for( int i=1; i<=N; i++ ) {
	printf("Case #%d: ", i ) ;
	caso() ;
    }
    
    return 0 ;
}
