#include <algorithm>
#include <cstdio>
#include <algorithm>
using namespace std ;

int main() {
	int K ;
	int arr[12], sum=0 ;
	
	scanf("%d", &K ) ;
	for( int i=0; i<12; i++ ) {
		scanf("%d", &arr[i] ) ;
	}
	
	if( K==0 ) {
		printf("0\n" ) ;
		return 0 ;
	}
	
	sort( arr, arr+12 ) ;
	for( int i=11; i>=0 && sum<=K; i--) {
		sum += arr[i] ;
		if( sum>=K ) {
			printf("%d\n", 12-i ) ;
			return 0 ;
		}
	}
	
	printf("-1\n" ) ;
	
	return 0 ;
}
