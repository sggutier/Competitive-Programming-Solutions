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
const int lim = 55 ;

int main() {
	int N, K ;
	int siz[lim] ;

	scanf("%d%d", &N, &K ) ;
	for( int i=0; i<N; i++ ) 
		scanf("%d", &siz[i] ) ;

	for( int i=0; i<N; i++ ) {
		for( int j=0; j<N; j++ ) {
			int cnt = 0 ;
			for( int k=0; k<N; k++ ) {
				if( siz[i]<=siz[k] && siz[j]<=siz[k] )
					cnt ++ ;
			}
			if( cnt==K ) {
				printf("%d %d\n", siz[i], siz[j] ) ;
				return 0 ;
			}
		}
	}

	printf("-1\n" ) ;

	return 0 ;
}

