#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
typedef long long ll ;

int main() {
	ll n, d, m, l ;
	ll pos=0LL, res = 0LL ;
	
	cin >> n >> d >> m >> l ;
	
	do {
		res += d ;
		pos += d ;
		pos %= m ;
	} while( pos!=0LL && pos<=l   )   ;
	
	if( pos==0LL ) {
		res =   (  m*(n-1LL) + l+1LL ) /  d ;
		if( (  m*(n-1LL) + l+1LL ) % d   )
			res ++ ;
		res *= d ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
