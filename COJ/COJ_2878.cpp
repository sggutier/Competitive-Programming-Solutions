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

char S[10005] ;

void caso() {
	gets(S) ;
	int N = strlen(S), res = -1 ;
	int cnt[26] ;
	memset( cnt, 0, sizeof(cnt) ) ;
	for( int i=0; i<N; i++ )
		if( S[i]!=' ' )
			cnt[ S[i]-'A' ] ++ ;
	for( int i=0; i<26; i++ ) 
		res = max( res, cnt[i] ) ;
	if( res==-1 ) {
		printf("NOT POSSIBLE\n" ) ;
		return ;
	}
	for( int i=0, k=0; i<26; i++ ) {
		if( cnt[i]==res ) {
			if( k ) {
				printf("NOT POSSIBLE\n" ) ;
				return ;
			}
			k ++ ;
		}
	}
	for( int i=0; i<26; i++ ) {
		if( cnt[i]==res ) {
			res = i-4 ;
			break ;
		}
	}

	printf("%d ", (res+26)%26 ) ;
	for( int i=0; i<N; i++ ) {
		if( S[i]==' ' )
			printf("%c", S[i] ) ;
		else
			printf("%c", (S[i]-'A'-res+26)%26 + 'A' ) ;
	}
	printf("\n" ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	gets(S) ;
	for( int i=0; i<T; i++ ) {
		caso() ;
	}

	return 0 ;
}

