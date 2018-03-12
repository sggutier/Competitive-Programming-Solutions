#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std; 
#define inf (1LL<<60) 

int main() {
	int n ;
	long long ini = -inf, fin = inf ;
	double b ;
	long long a ;
	
	scanf("%d", &n ) ;
	while( n ) {
		n -- ;
		scanf("%lf", &b ) ;
		a = (long long) ( b*2 ) ;
		if( ini>fin )
			continue ;
		fin = min( fin, a/2LL ) ;
		
		swap( ini, fin ) ;
		ini = a-ini ;
		fin = a-fin ;
	}
	
	cout << max( 0LL, fin-ini+1LL ) << endl ;
	
	return 0 ;
}
