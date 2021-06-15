#include <algorithm>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std ;

int main() {
	int N, K ;
	int p, q ;
	double x, y, a, b ;
	double res = 1.0*0 ;
	
	scanf("%d%d", &N, &K ) ;
	scanf("%d%d", &p, &q ) ;
	x = p*1.0 ;
	y = q*1.0 ;
	for( int i=1; i<N; i++ ) {
		scanf("%d%d", &p, &q ) ;
		a = p*1.0 ;
		b = q*1.0 ;
		res += sqrt( (a-x)*(a-x) + (b-y)*(b-y)   )   ;
		x = a ;
		y = b ;		
	}
	
	printf("%.9lf\n", res*K/50.0 ) ;
	
	return 0 ;
}


