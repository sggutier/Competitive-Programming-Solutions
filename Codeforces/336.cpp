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

int main() {
	int A ;
	double W, res=1.0*0 ;

	scanf("%d%d", &A, &W ) ;

	for( int i=0; i<A; i++ ) {
		res += W ;
		if( i-1>0 )
			res += (sqrt(2.0)+2)*W ;
		if( i+1<A )
			res += (sqrt(2.0)+2)*W ;

		if( i-2>0 ) {
			long long sum = i-1 ;
			res += sum*sqrt(8.0)*W ;
			sum = (sum*(sum+1LL))/2LL ;
			res += sum*W*2.0 ;
		}
		if( i+2<A ) {
			long long sum = A-i-2 ;
			res += sum*sqrt(8.0)*W ;
			sum = (sum*(sum+1LL))/2LL ;
			res += sum*W*2.0 ;
		}
	}

	res /= (A*1.0)*(A*1.0) ;

	printf("%lf\n", res ) ;

	return 0 ;
}


