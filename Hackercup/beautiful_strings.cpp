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
#include <stack>
using namespace std ;
const int lim = 1005 ;
const int limS = 26 ;

int N ;
char S[lim] ;
int freq[lim] ;

void caso( int T ) {
	int res = 0 ;

	memset( freq, 0, sizeof(freq) ) ;
	gets(S) ;
	N = strlen(S) ;

	for( int i=0; i<N; i++ ) {
		if( S[i]>='A' && S[i]<='Z' )
			S[i] -= 'A'-'a' ;
		if( S[i]>='a' && S[i]<='z' ) {
			freq[ S[i]-'a' ] ++ ;
		}
	}

	sort( freq, freq+limS ) ;
	for( int i=0; i<limS; i++ )
		res += freq[i]*(i+1) ;

	printf("Case #%d: ", T ) ;
	printf("%d\n", res ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	gets(S) ;
	for( int i=1; i<=T; i++ ) 
		caso(i) ;

	return 0 ;
}

