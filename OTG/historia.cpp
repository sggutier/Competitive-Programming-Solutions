#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

int main() {
	int N ;
	long long A, B ;
	long long res = 0LL ;
	int i ;
	
	scanf("%d",&N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%lld",&B ) ;
		if( !i ) 
			res += B ;
		else {
			if( B>A )
				res += B-A+1LL ;
			else
				res += 1LL ;
		}
		A = B ;
	}
	
	printf("%lld\n",res ) ;
	
	return 0 ;
}
