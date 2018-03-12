#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;

int main() {
	int N, M, S ;
	long long res = 0LL ;
	
	cin >> N >> M >> S ;
	if( S==1 ) {
		//cout << N*M << endl ;
		//return 0 ;
	}
	for( long long a=1LL; a<=N; a+=2 ) {
		for( long long b=1LL; b<=M; b+=2 ) {
			if( a*b>S )
				break ;
			if( a*b==S ) {
				res += ( 2LL * ( (a+1LL)/2LL * (b+1LL)/2LL ) -1LL  )  *  (N-a+1LL)*(M-b+1LL)  ;
				continue ;
			}
			for( long long c=a+2LL, d; c<=N; c+=2LL ) {
				if( (S-a*b)%(c-a)  )
					continue ;
				d = (S-a*b)/(c-a) ;
				if( d%2LL==0LL || d>=b )
					continue ;
				//cout << a << " " << b << " " << c << " " << d << endl ;
				res += 2LL*( N-c+1LL )*( M-b+1LL )   ;
			}
		}
	}
	
	cout << res << endl ;
	
	return 0 ;
}
