#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std ;

long long sumDig( long long W ) {
	long long res = 0LL ;
	
	while( W ) {
		res += W%10LL ;
		W /= 10LL ;
	}
	
	return res ;
}

long long solvEqA( long long B, long long C ) {	
	return (-B - (long long)( sqrt(B*B-4LL*C) ) ) / 2LL ;
}

long long solvEqB( long long B, long long C ) {	
	return (-B + (long long)( sqrt(B*B-4LL*C) ) ) / 2LL ;
}

int main() {
	long long N ;
	long long res = (1LL<<60) ;
	
	cin >> N ;
	
	for( int i=0; i<=81; i++ ) {
		long long tmp ;
		
		tmp = solvEqA( i, -N ) ;
		if( tmp>0LL && tmp*(tmp+sumDig(tmp)) == N  )
			res = min( res, tmp ) ;
			
		tmp = solvEqB( i, -N ) ;
		if( tmp>0LL && tmp*(tmp+sumDig(tmp)) == N  )
			res = min( res, tmp ) ;
	}
	
	if( res==(1LL<<60)  )
		res = -1 ;
		
	cout << res << endl ;
	
	return 0 ;
}
