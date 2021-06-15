#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std ;

int main() {
	int N, M ;
	long long res = 0LL ;
	
	scanf("%d%d", &N, &M ) ;
	for( int i=2; i<=N; i+=2 ) 
		for( int j=2; j<=M; j+=2 ) 
			res += (N-i+1)*(M-j+1) ;
	
	cout << res << endl ;
	
	
	return 0 ;
}
