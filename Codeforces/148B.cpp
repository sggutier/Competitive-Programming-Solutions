#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define eps 0.0000000001

int main() {
	double vP, vD, t, f ;
	double C, P=0 ;
	int res = 0 ;
	
	cin >> vP >> vD >> t >> f >> C;
	
	if( vD<=vP ) {
		printf("0\n" ) ;
		return 0 ;
	}
	
	P = t*vP ;
	while( P + eps<C ) {
		double x = P/(vD-vP) ;
		if( P+vP*x + eps >= C )
			break ;
		P += (2*x + f)*vP ;
		res ++ ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
