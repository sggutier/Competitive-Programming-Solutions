#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
	int N, K ;
	long long res = 0LL ;
	
	cin >> N >> K ;
	for( int i=0; i<N; i++ ) {
		long long a, b, c, d, K2 ;
		long long res2=0LL, res3=res2 ;
		
		cin >> a >> b >> c >> d ;
		a = max( 0LL, b-a ) ;
		K2 = K + 0LL ;
		
		res2 += K2*c + d ;
		if( a>0 ) {
			res3 += d ;
			K2 = max( 0LL, K2-a ) ;
			if( K2%a>0LL ) 
				res3 += (K2/a)*d + min( (K2%a + a)*c, d ) ;
			else
				res3 += (K2/a)*d  ;
		}
		else {
			res3 = (1LL<<60) ;
		}
		res += min( res2, res3 ) ;
		//cout << a << " " << c << " " << d << " -> " << res << " " << res2 << " " << res3 << endl ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}

