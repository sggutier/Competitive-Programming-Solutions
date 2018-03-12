#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std ;
const int lim = 300005 ;
const int limK = 26 ;

int W=0 ;
int trie[lim][limK] ;
bool adj[limK][limK], marc[lim] ;
int N = 0 ;
string arr[lim] ;
int tRes=0 ;
int res[lim], usd[limK] ;

void mete( string &S ) {
	int pos = 0 ;
	for( int i=0; i<S.size(); i++ ) {
		int tmp = S[i]-'a' ;
		if( !trie[pos][tmp] )
			trie[pos][tmp] = ++W ;
		pos = trie[pos][tmp] ;
	}
	marc[pos] = 1 ;
}

int buscaCiclo( int pos ) {
    if( usd[pos] ) {
        return usd[pos]!=-1 ;
    }

    usd[pos] = 1 ;
    for( int i=0; i<limK; i++ )
        if( adj[pos][i] && buscaCiclo(i) )
            return 1 ;
    usd[pos] = -1 ;

    return 0 ;
}

bool posb( string &S ) {
	memset( adj, 0, sizeof(adj) ) ;
	memset( usd, 0, sizeof(usd) ) ;

	for( int i=0, pos=0; i<S.size(); i++ ) {
		//cout << S[i] ;
		if( marc[pos] )
			return 0 ;
		int tmp = S[i]-'a' ;
		for( int j=0; j<limK; j++ ) {
			if( trie[pos][j] && j!=tmp ) {
				if( adj[j][tmp] )
					return 0 ;
				adj[tmp][j] = 1 ;
			}
		}
		pos = trie[pos][tmp] ;
	}

	for( int i=0; i<limK; i++ ) {
	    if( usd[i] )
            continue ;
        if( buscaCiclo(i) )
            return 0 ;
	}

	return 1 ;
}

int main() {
	freopen( "first.in",  "r", stdin ) ;
	freopen( "first.out", "w", stdout ) ;

	char tmp[lim] ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		scanf("%s", tmp ) ;
		arr[i] = tmp ;
		mete( arr[i] ) ;
	}

	for( int i=0; i<N; i++ ) {
		if( posb(arr[i]) )
			res[tRes++] = i ;
	}

	printf("%d\n", tRes ) ;
	for( int i=0; i<tRes; i++ ) {
	    int K = arr[res[i]].size() ;
	    for( int j=0; j<K; j++ )
            printf("%c", arr[res[i]][j] ) ;
		printf("\n" ) ;
	}

	return 0 ;
}
