#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 100005

void caso() {
	int N, res=0 ;
	char S[lim] ;
	
	scanf("%s", S ) ;
	N = strlen(S) ;
	
	for( int i=0; i<N; i++ )
		if( S[i]!='4' && S[i]!='7' )
			res ++ ;
	
	printf("%d\n", res ) ;
}

int main() {
	int T ;
	
	for( scanf("%d", &T); T; T-- )
		caso() ;
	
	return 0 ;
}

