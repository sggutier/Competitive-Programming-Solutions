#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std ;
const int lim = 1005 ;
const int limS = 20005 ;

int N ;
int arr[lim] ;

int stp( int a, int &m ) {
	m = 0 ;
	for( int i=1; i<N; i++ ) {
		int tmp = max(arr[i]-a, 0 ) ;
		if( tmp%i )
			tmp = tmp/i +1 ;
		else
			tmp = tmp/i ;
		m = max( m, tmp ) ;
	}

	int X = a-arr[0], res = abs( arr[N-1]-(-X+arr[0]+m*(N-1)) ) ;

	return max( X, res ) ;
}

int stp2( int a, int &m ) {
	m = (1<<30) ;
	for( int i=1; i<N; i++ ) {
		int tmp = max(arr[i]-a, 0 )/ i ;
		m = min( m, tmp ) ;
	}
	m %= (1<<30) ;

	int X =-a+arr[0], res = abs( arr[N-1]-(X+arr[0]+m*(N-1)) ) ;

	return max( X, res ) ;
}

int main() {
	int rA=(1<<30), rB=rA ;
	int x, y ;
	int tmp, tmp2 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &arr[i] ) ;

	sort( arr, arr+N ) ;

	for( int m=0; m<=limS; m++ ) {
		int p, q ;
		p = stp (m+arr[0], tmp) ;
		q = stp2(arr[0]-m, tmp) ;
		if( p<rA ) {
			x = m ;
			rA = p ;
		}
		if( q<rB ) {
			y = m ;
			rB = q ;
		}
	}

	printf("------\n" ) ;
	for( int i=0; i<N; i++ ) 
		printf("%d ", arr[i] ) ;
	printf("------\n" ) ;

	printf("%d\n", max( rA, rB ) );
	printf("%d %d\n", x, rA ) ;
	printf("%d %d\n", y, rB ) ;
	stp (x+arr[0], tmp ) ;
	stp2(arr[0]-y, tmp2) ;
	//if( rB>rA )
		printf("-> %d %d\n", arr[0]+x-rA, tmp ) ;
	//else
		printf("-} %d %d\n", arr[0]-y+rA, tmp2) ;

	cout << arr[0]-50 << endl ;
	stp2(arr[0]-50, tmp ) ;
	cout << tmp << endl ;
	
	return 0 ;
}

