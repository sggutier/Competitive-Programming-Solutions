#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std ;

int N ;
int rep[25] ;
int arr[300005] ;

int main() {
	int N, K;
	char tmp[25] ;
	long long res = 0LL ;
	
	scanf("%d%d", &N, &K ) ;
	K ++ ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", tmp ) ;
		arr[i] = strlen(tmp) ;
		if( i>=K )
			rep[ arr[i-K] ] -- ;
		res += rep[arr[i]]++ ;
	}
	
	cout << res << endl ;
	
	return 0 ;
}
