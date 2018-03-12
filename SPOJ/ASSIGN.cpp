#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std ;
const int lim = 20 ;
const int limW = (1<<lim) ;

queue <int> Q[2] ;
long long frms[limW] ;
int N ;
int arr[lim][lim] ;

void caso() {
	memset( frms, 0, sizeof(frms) ) ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) 
		for( int j=0; j<N; j++ ) 
			scanf("%d", &arr[i][j] ) ;

	Q[0].push(0) ;
	frms[0] = 1LL ;
	for( int i=0, act=0, sig=1; i<N; i++, swap(act,sig)  ) {
		while( !Q[act].empty() ) {
			int pos = Q[act].front() ;
			Q[act].pop() ;
			for( int j=0; j<N; j++ ) {
				if( !arr[i][j] || ((1<<j)&pos) )
					continue ;
				int pos2 = pos+(1<<j) ;
				if( !frms[pos2] )
					Q[sig].push(pos2) ;
				frms[pos2] += frms[pos] ;
			}
		}
	}

	for( int i=0; i<2; i++ )
		while( !Q[i].empty() )
			Q[i].pop() ;

	printf("%lld\n", frms[(1<<N)-1] ) ;
}

int main() {
	int N=1 ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		caso() ;

	return 0 ;
}
