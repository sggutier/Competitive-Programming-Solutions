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
const int lim = 100005 ;
#define par pair<int,int>
#define f first
#define s second

struct odr {
	int a, b, pos ;
	odr( int _a, int _b, int _pos ) {
		a = _a ;
		b = _b ;
		pos = _pos ;
	}
	odr() {
	}
};

bool operator<( odr A, odr B ) {
	if( A.b != B.b )
		return A.b < B.b ;
	if( A.a != B.a ) 
		return A.a < B.a ;
	return A.pos < B.pos ;
}

bool funca( odr A, odr B ) {
	if( A.a != B.a ) 
		return A.a < B.a ;
	if( A.b != B.b )
		return A.b < B.b ;
	return A.pos < B.pos ;
}

int N, P, K, R ;
odr arr[lim] ;
priority_queue <odr> Q, QRes ;

int main() {
	scanf("%d%d%d", &N, &P, &K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &arr[i].a, &arr[i].b ) ;
		arr[i].pos = i ;
	}
	sort( arr, arr+N ) ;
	R = P-K ;
	//printf("----------\n" ) ;
	//for( int i=0; i<N; i++ ) 
	//	printf("%d %d %d\n", arr[i].a, arr[i].b, arr[i].pos+1 ) ;
	//printf("----------\n" ) ;

	sort( arr+R, arr+N, funca ) ;
	//printf("----------\n" ) ;
	//for( int i=0; i<N; i++ ) 
		//printf("%d %d %d\n", arr[i].a, arr[i].b, arr[i].pos+1 ) ;
	//printf("----------\n" ) ;
	sort( arr, arr+(N-K)  ) ;

	//printf("----------\n" ) ;
	//for( int i=0; i<N; i++ ) 
		//printf("%d %d %d\n", arr[i].a, arr[i].b, arr[i].pos+1 ) ;
	//printf("----------\n" ) ;

	for( int i=N-K-1, w=R; i>=0 && w>0; i-- ) {
		if( arr[i].b<arr[N-K].b ) {
			printf("%d ", arr[i].pos+1 ) ;
			w -- ;
		}
		else if( arr[i].b==arr[N-K].b && arr[i].a>arr[N-K].a ) {
			printf("%d ", arr[i].pos+1 ) ;
			w -- ;
		}
	}
	for( int i=N-K; i<N; i++ ) 
		printf("%d ", arr[i].pos+1 ) ;
	printf("\n" ) ;

	return 0 ;
}


