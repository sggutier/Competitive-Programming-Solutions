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
const long long mod = 1000000009LL ;

long long expBin( long long X ) {
	if( X==1LL )
		return 1LL ;
	long long tmp = expBin(X/2LL) ;
	if( X%2LL )
		return tmp*tmp*2LL ;
	return tmp*tmp ;
}

int main() {
	long long N, K, M ;
	long long W, foo ;
	long long res = 0LL ;

	cin >> N >> M >> K ;

	W = (M/K)*(K-1LL) + (M%K) ;

	if( W<M ) {
		res += ( (M-W)*2LL*(expBin(M-W)-1LL) )%mod ;
		W -= (M-W)*(K-1) ;
		res = (res+W)%mod ;
	}
	else
		res = W ;

	cout << res << endl ;

	return 0 ;
}


