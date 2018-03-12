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
const int lim = 20 ;
const int limW = 1<<lim ;

struct sta {
	int arr[205], pos ;
	sta() {
		memset( arr, 0, sizeof(arr) ) ;
	}
};

int cer[lim], tam[lim], lav[lim][lim*3] ;
int ant[limW], usd[limW] ;
queue <sta> Q ;

void caso() {
	memset( usd, 0, sizeof(usd) ) ;

	sta ini ;
	int N, K ;
	int res[limW] ;

	scanf("%d%d", &K, &N ) ;
	for( int i=0; i<K; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		ini.arr[tmp] ++ ;
	}
	for( int i=0; i<N; i++ ) {
		scanf("%d%d", &cer[i], &tam[i] ) ;
		for( int j=0; j<tam[i]; j++ ) 
			scanf("%d", &lav[i][j] ) ;
	}

	ini.pos = 0 ;
	Q.push( ini ) ;
	while( !Q.empty() ) {
		sta pos = Q.front() ;
		Q.pop() ;

		for( int i=0; i<N; i++ ) {
			if( ((1<<i) & pos.pos )  ||  pos.arr[ cer[i] ]==0  ||  usd[ pos.pos + (1<<i) ] )
				continue ;
			sta sig = pos ;
			sig.pos += (1<<i) ;
			sig.arr[ cer[i] ] -- ;
			for( int j=0; j<tam[i]; j++ ) {
				sig.arr[ lav[i][j] ] ++ ;
			}
			usd[ sig.pos ] = 1 ;
			ant[ sig.pos ] = i ;
			Q.push( sig ) ;
		}
	}

	if( usd[(1<<N)-1]==0 ) {
		printf("IMPOSSIBLE\n" ) ;
		return ;
	}

	for( int i=N-1, pos=(1<<N)-1; pos; i-- ) {
		res[i] = ant[pos] ;
		pos -= (1<<ant[pos]) ;
	}

	for( int i=0; i<N; i++ ) 
		printf("%d ", res[i] +1 ) ;
	printf("\n" ) ;
}

int main() {
	int T ;

	scanf("%d", &T ) ;
	for( int i=1; i<=T; i++ ) {
		printf("Case #%d: ", i ) ;
		caso() ;
	}

	return 0 ;
}


