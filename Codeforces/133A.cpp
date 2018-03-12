#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std ;
#define lim 300000

bool usd[lim] ;

int main() {
	int N ;
	char S[lim] ;
	usd['H'] = 1 ;
	usd['Q'] = 1 ;
	usd['9'] = 1 ;
	
	gets( S ) ;
	N = strlen(S) ;
	
	for( N--; N>=0 && !usd[S[N]]; N-- ) ;
	
	if( N>=0 )
		printf("YES\n" ) ;
	else
		printf("NO\n" ) ;
	
	return 0 ;
}
