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
const int lim = 100005 ;

bool usd[lim] ;

int main() {
	int N ;
	char S[lim] ;
	int a=1, b=0, x=10 ;

	scanf("%s", S ) ;
	N = strlen(S) ;

	if( S[0]=='0' ) {
		printf("0\n" ) ;
		return 0 ;
	}
	if( S[0]>='A' && S[0]<='Z' ) {
		a *= 9 ;
		x -- ;
		usd[S[0]] = 1 ;
	}
	else if( S[0]=='?' )
		a = 9 ;

	for( int i=1; i<N; i++ ) {
		if( S[i]>='A' && S[i]<='Z' && !usd[S[i]] ) {
			a *= x ;
			x -- ;
			usd[S[i]] = 1 ;
		}
		else if( S[i]=='?' )
			b ++ ;
	}

	printf("%d", a ) ;
	for( int i=0; i<b; i++ )
		printf("0" ) ;
	printf("\n" ) ;

	return 0 ;
}


