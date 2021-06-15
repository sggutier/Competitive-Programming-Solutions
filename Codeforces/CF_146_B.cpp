#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <cstring>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second

int N, M ;
char S[100], W[100] ;


bool prueba( int A ) {
	M = 0 ;
	while( A ) {
		if( A%10 == 4 || A%10 == 7  )
			W[M++] = (A%10)+'0'  ;
		A /= 10 ;
	}
	
	if( M!=N )
		return 0 ;
		
	for( int i=0; i<N; i++ ) {
		if( S[i]!=W[M-i-1]  )
			return 0 ;
	}
	
	return 1 ;
}

int main() {
	int A, B ;
	
	cin >> A >> B ;
	
	sprintf( S, "%d", B ) ;
	N = strlen( S ) ;
	for( A++;  !prueba( A ); A++ ) ;
	
	cout << A << endl ;
	
	return 0 ;
}
