#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
using namespace std ;
#define lim 500

stack <int> Q ;

int main() {
	int N, W=0 ;
	char S[lim], id[lim] ;
	
	//scanf("%s", S ) ;
	gets(S) ;
	N = strlen(S) ;
	
	for( int i=0; i<N; i++ ) {
		id[i] = 25 ;
		if( S[i]=='(' ) {
			id[i] = W++ ;
			Q.push(i) ;
		}
		else if( S[i]==')' ) {
			id[i] = id[Q.top()] ;
			Q.pop() ;
		}
	}
	
	for( int b=1; b<(1<<W); b++ ) {
		for( int i=0; i<N; i++ )
			if( ( (1<<(W-id[i]-1)) & b )==0  ||  id[i]==25  )
				printf("%c", S[i] ) ;
		printf("\n" ) ;
	}
	
	return 0 ;
}
