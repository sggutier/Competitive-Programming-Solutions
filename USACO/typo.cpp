#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 100005 ;

int N ;
int le[lim], ro[lim] ;
char S[lim] ;

int main() {
	freopen( "typo.in", "r", stdin ) ;
	freopen( "typo.out", "w", stdout ) ;

	int res = 0 ;

	scanf("%s", S ) ;
	N = strlen(S) ;

	for( int i=N-1; i>=0; i-- ) {
		if( i+1<N )
			ro[i] = ro[i+1] ;
		if( ro[i]==-1 )
			continue ;
		if( S[i]==')' ) 
			ro[i] ++ ;
		else
			ro[i] -- ;
	}
	for( int i=0; i<N; i++ ) {
		if( i )
			le[i] = le[i-1] ;
		if( le[i]==-1 )
			continue ;
		if( S[i]=='(' ) 
			le[i] ++ ;
		else
			le[i] -- ;
	}

	for( int i=0; i<N; i++ ) {
		int a=0, b=0 ;
		if( i )
			a = le[i-1] ;
		if( i+1<N )
			b = ro[i+1] ;
		if( a==-1 || b==-1 )
			continue ;
		if( S[i]==')' ) {
			if( a+1==b )
				res ++ ;
		}
		else {
			if( a==b+1 )
				res ++ ;
		}
	}

	printf("%d\n", res ) ;

	return 0 ;
}

