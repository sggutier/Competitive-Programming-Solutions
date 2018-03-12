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
const int limN = 100005 ;
const int limK = 1005 ;

int N ;
int adj[limK][limK] ;
list <int> cnt[limN] ;
int minP[limN], usd[limK] ;
queue <int> Q ;

int main() {
	int E, K ;

	scanf("%d%d%d", &N, &K, &E ) ;
	for( int i=0; i<E; i++ ) {
		for( int j=0; j<K; j++ ) {
			scanf("%d", &adj[i][j]  ) ;
			adj[i][j] -- ;
			cnt[ adj[i][j] ].push_back( i ) ;
		}
	}

	Q.push( 0 ) ;
	minP[0] = 1 ;
		while( !Q.empty() ) {
			int pos = Q.front() ;
			Q.pop() ;

			for( list<int>::iterator it=cnt[pos].begin();  it!=cnt[pos].end();  it++  ) {
				int tmp = *it ;
				if( usd[tmp] )
					continue ;
				usd[tmp] = 1 ;
				for( int i=0; i<K; i++ ) {
					if( minP[ adj[tmp][i] ] )
						continue ;
					minP[ adj[tmp][i] ] = minP[pos] +1 ;
					Q.push( adj[tmp][i] ) ;
				}
			}
		}

	printf("%d\n", minP[N-1] ) ;

	return 0 ;
}


