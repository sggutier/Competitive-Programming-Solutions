#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 1000 ;

bool usd[lim] ;

int main() {
	long long W ;
	long long res = 1LL ;

	cin >> W ;

	for( int i=2; ; i++ ) {
		if( usd[i] )
			continue ;
		long long tmp = (long long) ( pow(W,1.0/i) ) ;
		cout << tmp << " " << i << " " << (long long) (pow(tmp,i)) << endl ;
		if( tmp==1LL )
			break ;
		res += tmp-1LL ;
		for( int j=i*i; j<lim; j+=i )
			usd[j] = 1 ;
	}

	cout << res << endl ;

	return 0 ;
}

