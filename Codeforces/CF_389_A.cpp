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
const int lim = 105 ;

int N ;
int arr[lim] ;

int gcd( int a, int b ) {
	int c ;
	while( b ) {
		c = a%b ;
		a = b ;
		b = c ;
	}
	return a ;
}

int main() {
	int A ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )  {
		scanf("%d", &arr[i] ) ;
		if( !i )
			A = arr[i] ;
		A = gcd( A, arr[i] ) ;
	}
	
	printf("%d\n", A*N ) ;

	return 0 ;
}

