#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
using namespace std ;
#define par pair<int,int>
#define f first
#define s second

int main() {
	int N, M ;
	int res[1005] ;
	par carg[40] ;
	int i, j ;
	int a, b ;
	
	scanf("%d%d",&N,&M ) ;
	for( i=0; i<M; i++ ) {
		scanf("%d", &carg[i].f ) ;
		carg[i].s = i+1 ;
	}
	
	memset( res, 0, sizeof(res)  ) ;
	for( i=0; i<1; i++ ) {
		sort( carg, carg + M ) ;
		reverse( carg, carg + M ) ;
		for( j=0; j<M && ( !carg[j].f  ||  carg[j].s == res[(i+1)%N]  ||  carg[j].s == res[(i+N-1)%N]  ) ;  j++  )  ;
		if( j==M ) {
			printf("-1\n" ) ;
			return 0 ;
		}
		res[i] = carg[j].s ;
		carg[j].f -- ;
	}
	for( a=1, b=N-1; a<=b; a++, b-- ) {
		sort( carg, carg + M ) ;
		reverse( carg, carg + M ) ;
		for( j=0; j<M && ( !carg[j].f  ||  carg[j].s == res[(a+1)%N]  ||  carg[j].s == res[(a+N-1)%N]  ) ;  j++  )  ;
		if( j==M ) {
			printf("-1\n" ) ;
			return 0 ;
		}
		res[a] = carg[j].s ;
		carg[j].f -- ;
		
		if( a==b )
			continue ;
		sort( carg, carg + M ) ;
		reverse( carg, carg + M ) ;
		for( j=0; j<M && ( !carg[j].f  ||  carg[j].s == res[(b+1)%N]  ||  carg[j].s == res[(b+N-1)%N]  ) ;  j++  )  ;
		if( j==M ) {
			printf("-1\n" ) ;
			return 0 ;
		}
		res[b] = carg[j].s ;
		carg[j].f -- ;
	}
	
	for( i=0; i<N; i++ ) 
		printf("%d ", res[i] ) ;
	printf("\n" ) ;

	return 0 ;
}
