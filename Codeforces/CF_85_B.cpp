#include <algorithm>
#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std ;
#define par pair<long long,long long>
#define f first
#define s second
#define inf (1LL<<60)

int main() {
	int k[3], t[3] ;
	int N ;
	par c[100000] ;
	queue <par> in[4], out[4] ;
	int i, j ;
	long long x ;
	par tmp ;
	
	for( i=0; i<3; i++ ) 
		scanf("%d",&k[i] ) ;
	for( i=0; i<3; i++ ) 
		scanf("%d",&t[i] ) ;
	scanf("%d",&N ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d",&j  ) ;
		c[i] = par( j+0LL, 0LL )  ;
	}
	
	sort( c, c+N ) ;
	for( i=0; i<N; i++ )
		in[0].push( c[i] ) ;
	while( in[3].size() < N )  {
		x = inf ;
		for( i=0; i<3; i++ ) 
			if( !out[i].empty()  )
				x = min( x, out[i].front().f  )  ;
		x %= inf ;
		
		for( i=0; i<3; i++ ) {
			while( !out[i].empty()  &&  out[i].front().f == x  ) {
				in[i+1].push(  out[i].front()  ) ;
				out[i].pop() ;
				k[i] ++ ;
			}
		}
		for( i=0; i<3; i++ ) {
			while( !in[i].empty() && k[i] ) {
				k[i] -- ;
				tmp = in[i].front() ;
				in[i].pop() ;
				tmp.s += max( 0LL, x-tmp.f ) + t[i];
				tmp.f = max( tmp.f, x ) ;
				tmp.f += t[i] ;
				out[i].push( tmp ) ;
			}
		}
	}
	
	x = 0 ;
	while( !in[3].empty()  )  {
		x = max( x, in[3].front().s ) ;
		in[3].pop() ;
	}
	
	cout << x << endl ;
	
	return 0 ;
}
