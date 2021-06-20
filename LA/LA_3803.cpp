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
const int lim = 150005 ;

struct trie {
	int tam ;
	int sig[lim][26] ;
	trie() {
		tam = 0 ;
	}
	void reset() {
		memset( sig, 0, sizeof(sig) ) ;
		tam = 0 ;
	}
	void mete( char S[], int nS ) {
		for( int pos=0, i=0; i<nS; pos=sig[pos][S[i]-'a'], i++ ) {
			if( sig[pos][S[i]-'a']==0 )
				sig[pos][S[i]-'a'] = ++tam ;
		}
	}
};

int N, M ;
trie pref, suf ;
unsigned long long res, sum ;
unsigned long long repL[26] ;

void dfs( trie &arb, int pos, int tip ) {
	if( pos )
		res += sum*(1-tip) ;
	for( int i=0; i<26; i++ ) {
		if( !arb.sig[pos][i] )
			continue ;
		if( pos ) {
			repL[i] += tip ;
			res -= repL[i]*(1-tip) ;
		}
		dfs( arb, arb.sig[pos][i], tip ) ;
	}
}

void caso() {
	char tmp[1005] ;

	pref.reset() ;
	suf.reset() ;
	for( int i=0; i<26; i++ )
		repL[i] = 0ULL ;
	res = 0ULL ;

	for( int i=0; i<N; i++ ) {
		scanf("%s", tmp ) ;
		int k = strlen(tmp) ;
		pref.mete( tmp, k ) ;
	}
	for( int i=0; i<M; i++ ) {
		scanf("%s", tmp ) ;
		int k = strlen(tmp) ;
		reverse( tmp, tmp+k ) ;
		suf.mete( tmp, k ) ;
	}

	sum = suf.tam ;
	dfs( suf, 0, 1 ) ;
	dfs( pref, 0, 0 ) ;

	printf("%llu\n", res ) ;
}

int main() {
	scanf("%d%d", &N, &M ) ;

	caso() ;

	cout << repL[0] << endl ;

	return 0 ;
}


