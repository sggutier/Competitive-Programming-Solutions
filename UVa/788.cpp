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

long long N ;
map <long long,bool> dp ;

bool memo( long long pos ) {
	if( pos>=N )
		return 0 ;
	if( dp.find(pos)!=dp.end() )
		return dp[pos] ;
	bool tmp = 0 ;
	for( int i=2; i<10; i++ ) {
		if( memo(pos*i) )
			continue ;
		tmp = 1 ;
		break ;
	}
	return dp[pos]=tmp ;
}

void caso() {
	dp.clear() ;
	
	memo(1LL) ;

	printf("%s\n", dp[1LL]==1? "Stan wins.":"Ollie wins." ) ;
}

int main() {
	while( scanf("%lld", &N)!=EOF )
		caso() ;

	return 0 ;
}

