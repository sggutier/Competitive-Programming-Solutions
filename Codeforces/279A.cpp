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
const int lim = 1000006 ;

int N ;
char S[lim] ;

int main() {
	int res = 0 ;

	scanf("%s", S ) ;
	N = strlen(S) ;

	for( int i=0, k, z=0, w=0; i<N; i=k ) {
		if( S[i]=='0' ) {
			k = i+1 ;
			z ++ ;
			continue ;
		}
		for( k=i+1; k<N && S[k]=='1'; k++ ) ;
		if( z==1 && w ) {
			res ++ ;
			w = 1 ;
		}
		else if( k-i==1 ) {
			res ++ ;
			w = 0 ;
		}
		else {
			res += 2 ;
			w = 1 ;
		}
		z = 0 ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}


