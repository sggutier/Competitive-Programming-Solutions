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
const int lim = 1000006 ;
const long long mod = 1000000007LL ;

long long tree[lim] ;
long long usd[lim] ;

void mete( int pos, long long val ) {
	for( ; pos<lim; pos += (pos&-pos) )
		tree[pos] = (tree[pos]+val)%mod ;
}

long long saca( int pos) {
	long long foo = 0LL ;
	for( ; pos>0; pos -= (pos&-pos)  )
		foo = (foo+tree[pos])%mod ;
	return foo ;
}

int main() {
	int N ;
	long long res = 0LL ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		long long foo ;
		scanf("%d", &tmp ) ;

		foo = (saca( tmp )*tmp + tmp)%mod ;

		mete( tmp, (foo-usd[tmp]+mod)%mod ) ;
		usd[tmp] = foo ;
	}

	cout << saca(lim-1) << endl ;

	return 0 ;
}


