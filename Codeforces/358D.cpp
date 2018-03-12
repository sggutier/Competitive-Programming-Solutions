#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 3005 ;

int N ;
int A[lim], B[lim], C[lim] ;
int DP[lim][2] ;
bool usd[lim][2] ;

int memo( int L, int tip ) {
	if( usd[L][tip] )
		return DP[L][tip] ;
	usd[L][tip] = 1 ;

	if( tip==0 ) 
		return DP[L][tip] = max( memo(L+1, 1) + A[L], memo(L+1, 0) + B[L] ) ;
	else
		return DP[L][tip] = max( memo(L+1, 1) + B[L],  memo(L+1,0) + C[L] ) ;
}

int main() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &A[i] ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &B[i] ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &C[i] ) ;

	usd[N-1][0] = 1 ;
	usd[N-1][1] = 1 ;
	DP[N-1][0] = A[N-1] ;
	DP[N-1][1] = B[N-1] ;

	printf("%d\n", memo(0,0)  ) ;

	return 0 ;
}


