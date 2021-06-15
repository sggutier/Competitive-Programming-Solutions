#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	freopen( "input.txt", "r", stdin ) ;
	freopen( "output.txt", "w", stdout ) ;
	
	int N, pos ;
	int arr[10000] ;
	
	scanf("%d%d", &N, &pos ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
		
	pos -- ;
	while( !arr[pos] ) pos = (pos+1)%N ;
	
	printf("%d\n", pos+1  ) ;
	
	return 0 ;
}
