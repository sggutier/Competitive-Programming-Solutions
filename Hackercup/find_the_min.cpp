#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <stack>
using namespace std ;
const int lim = 100005 ;

int N, K ;
long long a, b, c, r ;
long long arr[lim] ;
bool usd[lim] ;

void caso() {
	long long ult ;

	scanf("%d%d%lld%lld%lld%lld", &N, &K, &a, &b, &c, &r ) ;

	memset( usd, 0, sizeof(usd)  ) ;
	arr[0] = ult = a ;
	for( int i=1; i<N; i++ ) {
		arr[i%K] = ult = (b*ult+c)%r ;
		cout << ult << endl ;
	}

	for( int i=0; i<K; i++ ) 
		if( arr[i]<lim )
			usd[ arr[i] ] = 1 ;

	for( int i=0; i<lim; i++ ) {
		if( usd[i] )
			continue ;
		printf("%d\n", i ) ;
		return ;
	}
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ ) {
		//printf("Case #%d: ", i+1 ) ;
		caso() ;
		cout << "----------\n" ;
	}

	return 0 ;
}

