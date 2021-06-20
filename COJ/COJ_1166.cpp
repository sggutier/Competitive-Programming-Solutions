#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

void caso() {
	int N ;
	int res[2] ;
	
	res[0] = 0 ;
	res[1] = 0 ;
	
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )  {
		string A ;
		cin >> A ;
		res[A[A.size()-1]%2LL] ++ ;
	}
	
	printf("%d even and %d odd.\n", res[0], res[1] ) ;
}

int main() {
	int T ;
	
	scanf("%d", &T ) ;
	for( int i=0; i<T; i++ )
		caso() ;
	
	return 0 ;
}
