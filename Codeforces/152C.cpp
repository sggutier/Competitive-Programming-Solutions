#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std ;
#define lim 300
#define mod 1000000007LL

int main() {
	int N, M ;
	char S[lim] ;
	int rep[lim][lim] ;
	long long res = 1LL ;
	
	memset( rep, 0, sizeof(rep) ) ;
	
	scanf("%d%d", &N, &M ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", S ) ;
		for( int j=0; j<M; j++ ) {
			rep[j][ int(S[j]) ] = 1 ;
		}
	}
	
	for( int i=0; i<M; i++ ) {
		int W = 0 ;
		for( int j=0; j<lim; j++ ) {
			W += rep[i][j] ;
		}
		res = (res*W)%mod ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
