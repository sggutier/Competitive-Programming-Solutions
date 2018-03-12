#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int N, K ;
	
	scanf("%d%d", &N, &K ) ;
	
	for( int i=0; i<=N; i++ ) {
		for( int j=N-i; j>=0; j-- ) {
			for( int k=N-i-j; k>=0; k-- ) {
				int w=N-i-j-k;
				if( 2*i + 3*j + 4*k + 5*w == K ) {
					printf("%d\n", i ) ;
					return 0 ;
				}
			}
		}
	}
	
	return 0 ;
}
