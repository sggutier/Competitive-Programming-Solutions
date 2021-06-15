#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 1000
#define mod 256

int rev( int W ) {
	int res = 0 ;
	for( int i=0; i<8; i++ ) 
		if( (1<<i)&W )
			res += (1<<(7-i)) ;
	return res ;
}

int N ;
char S[lim] ;

int main() {
	int prev = 0, act ;
	
	gets(S) ;	
	N = strlen(S) ;
	
	for( int i=0; i<N; i++ ) {
		prev = rev(prev) ;
		prev = (mod+prev-rev(S[i]))%mod ;
		printf("%d\n", prev ) ;
		prev = S[i] ;
	}
	
	return 0 ;
}
