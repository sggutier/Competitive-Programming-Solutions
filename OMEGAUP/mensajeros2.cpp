#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
using namespace std ;
#define par pair<long long,int>
#define f first
#define s second
const int lim = 100005 ;

int N, W=0 ;
list <par> adj[lim] ;
long long v[lim], s[lim] ;
long long res[lim] ;
int arr[lim] ;
long long dis[lim] ;

void busca( int pos, int ant, long long carg ) {
        dis[pos] = carg ;
        if( pos ) {
                res[pos] = (1LL<<60) ;
                for( int i=0; i<W; i++ )
                        res[pos] = min( res[pos], (carg-dis[ arr[i] ])*v[pos] + res[ arr[i] ] ) ;
                res[pos] += s[pos] ;
        }
        
        arr[W++] = pos ;

        for( list<par>::iterator it=adj[pos].begin(); it!=adj[pos].end();  it++   ) {
                if( it->s != ant )
                        busca( it->s, pos, carg + it->f ) ;
        }

        W-- ;
}

int main() {
        scanf("%d", &N ) ;
        for( int i=1; i<N; i++ ) {
                long long c ;
                int a, b ;
		cin >> a >> b >> c ;
                a--, b-- ;
                adj[a].push_back( par(c,b) ) ;
                adj[b].push_back( par(c,a) ) ;
        }
        for( int i=1; i<N; i++ ) 
		cin >> s[i] >> v[i] ;

        busca( 0, -1, 0LL ) ;

        for( int i=1; i<N; i++ )
		cout << res[i] << endl ;
	cout << endl ;

        return 0 ;
}

