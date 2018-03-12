#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;
#define lim 1000

int main() {
	freopen( "input.txt", "r", stdin ) ;
	freopen( "output.txt", "w", stdout ) ;
	
	int N, K ;
	int arr[lim], res=0 ;
	
	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%d", &arr[i] ) ;
		for( int j=0; j<3 && arr[i]>=K; j++, arr[i]-=K ) ;
		printf("potato\n" ) ;
		
		res += arr[i] ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}
