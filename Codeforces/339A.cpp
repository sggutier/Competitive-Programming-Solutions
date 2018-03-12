#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 100005 ;

char res[lim] ;
char S[lim] ;

int main() {
	int N = 0 ;

	scanf("%s", S ) ;

	for( int i=0; S[i]; i++ )
		if( S[i]!='+' )
			res[N++] = S[i] ;
	
	sort( res, res+N ) ;

	for( int i=0; i<N; i++ ) {
		if( i )
			printf("+" ) ;
		printf("%c", res[i] ) ;
	}
	printf("\n" ) ;

	return 0 ;
}


