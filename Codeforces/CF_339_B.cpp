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

int main() {
	int mod, N ;
	long long res = 0LL ;

	scanf("%d%d", &mod, &N ) ;

	for( int i=0, pos=0, tmp; i<N; i++ ) {
		scanf("%d", &tmp ) ;
		res += (mod+tmp-1-pos)%mod ;
		pos = tmp-1 ;
	}

	cout << res << endl ;

	return 0 ;
}


