#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <list>
#include <stack>
using namespace std ;
const int lim = 400 ;

int rep[lim] ;

int main() {
	int N ;
	char S[lim] ;

	scanf("%d", &N ) ;
	gets(S) ;
	for( int i=0; i<N; i++ ) {
		int W ;
		gets(S) ;
		W = strlen(S) ;

		memset( rep, 0, sizeof(rep) ) ;
		for( int i=0; i<W; i++ ) {
			if( S[i]>='A' && S[i]<='Z' )
				S[i] = S[i] - 'A' + 'a' ;
			rep[ S[i] ] = 1 ;
		}

		for( int i='a'; i<='z'; i++ ) {
			if( rep[i] )
				continue ;
			W = -1 ;
			printf("%c\n", i ) ;
			break ;
		}
		if( W!=-1 )
			printf("~\n" ) ;
	}

	return 0 ;
}


