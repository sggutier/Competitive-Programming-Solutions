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
const int lim = 5000006 ;
#define foo unsigned long long
const foo bas = 63ULL ;

int N ;
char S[lim] ;
foo ro[lim], pot[lim], le=0ULL ;
int deg[lim] ;
foo res = 0ULL ;

int main() {
	gets(S) ;

	N = strlen(S) ;

	if( 1 ) {
		int i = 0 ;
		foo tmp = S[i] ;
		if( tmp>='a' && tmp<='z' ) {
			tmp -= 'a' ;
		}
		else if( tmp>='A' && tmp<='Z' ) {
			tmp += 26 - 'A' ;
		}
		else {
			tmp += 52 - '0' ;
		}

		pot[i] = 1ULL ;
		le = tmp ;

		tmp = S[N-i-1] ;
		if( tmp>='a' && tmp<='z' ) {
			tmp -= 'a' ;
		}
		else if( tmp>='A' && tmp<='Z' ) {
			tmp += 26 - 'A' ;
		}
		else {
			tmp += 52 - '0' ;
		}
		ro[N-i-1] = tmp ;
	}
	for( int i=1; i<N; i++ ) {
		pot[i] = pot[i-1] * bas ;

		foo tmp = S[N-i-1] ;
		if( tmp>='a' && tmp<='z' ) {
			tmp -= 'a' ;
		}
		else if( tmp>='A' && tmp<='Z' ) {
			tmp += 26 - 'A' ;
		}
		else {
			tmp += 52 - '0' ;
		}
		ro[N-1-i] = ro[N-i]*bas + tmp ;
	}

	deg[0] = 1ULL ;
	res ++ ;

	for( int i=1; i<N; i++ ) {
		foo tmp = S[i] ;
		if( tmp>='a' && tmp<='z' ) {
			tmp -= 'a' ;
		}
		else if( tmp>='A' && tmp<='Z' ) {
			tmp += 26 - 'A' ;
		}
		else {
			tmp += 52 - '0' ;
		}
		le = le*bas + tmp ;

		if( le == ro[0] - ro[i+1]*pot[i+1] ) {
			deg[i] = deg[(i-1)/2]+1 ;
		}
		res += deg[i] ;
	}

	cout << res << endl ;

	return 0 ;
}

