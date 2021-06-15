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
const int lim = 1005 ;

int rep[lim] ;

int main() {
	string S ;
	int W, K=0 ;

	cin >> S ;
	cin >> W ;

	for( int i=0; i<S.size(); i++ ) {
		if( !rep[S[i]] )
			K ++ ;
		rep[S[i]] ++ ;
	}

	if( K>W ) {
		printf("-1\n" ) ;
		return 0 ;
	}

	for( int i=1; ; i++ ) {
		int ns = 0 ;
		for( int j=0; j<lim; j++ ) {
			ns += rep[j]/i ;
			if( rep[j]%i )
				ns ++ ;
		}
		if( ns<=W ) {
			printf("%d\n", i) ;
			for( int j=0; j<lim; j++ ) {
				int tmp = rep[j]/i ;
				if( rep[j]%i )
					tmp ++ ;
				while( tmp ) {
					printf("%c", j ) ;
					tmp -- ;
				}
			}
			while( ns<W ) {
				printf("a") ;
				ns ++ ;
			}
			printf("\n" ) ;
			return 0 ;
		}
	}

	return 0 ;
}


