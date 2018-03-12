#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std ;
typedef pair<int,int> par ;
#define f first
#define s second

bool rang( int a, int b ) {
	int x=2*b, y=3*b ;
	a *= 6 ;
	return x<a && a<y ;
}

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
	int N ;
	int res = 0 ;
	
	cin >> N ;
	
	for( int i=2; i<=N; i++ ) {
		for( int j=1; j<i; j++ ) {
			if( gcd(i,j)==1 ) {
				if( rang(j,i) ) 
					res ++ ;
			}
		}
	}
	
	cout << res << endl ;
	
	return 0 ;
}
