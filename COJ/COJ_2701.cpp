#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std ;

int main() {
	char S[100] ;
	int N ;
	int sum=0, A, B ;

	scanf("%s", S ) ;
	N = strlen(S) ;

	for( int i=0; i<N; i++ ) 
		sum += S[i]-'A'+1 ;

	A = B = sum/2 ;
	if( sum%2 )
		B ++ ;

	while( A ) {
		printf("%c", min(A-1,25)+'A' ) ;
		A -= min( A, 26 ) ;
	}
	printf(" " ) ;
	while( B ) {
		printf("%c", min(B-1,25)+'A' ) ;
		B -= min( B, 26 ) ;
	}
	printf("\n" ) ;

	return 0 ;
}

