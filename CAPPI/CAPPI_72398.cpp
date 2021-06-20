#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
using namespace std ;
#define lim 1000007

int N, M ;
list<int> sig[lim] ;
int carg[lim] ;
int res[lim] ;

int main() {
	int R=0, R2=0 ;
	int a, b ;
	int i, j ;
	list<int>::iterator  it ;
	
	scanf("%d%d", &N, &M ) ;
	for( i=0; i<M; i++ ) {
		scanf("%d%d", &a, &b ) ;
		a--, b-- ;
		sig[a].push_back( b ) ;
		carg[b] ++ ;
	}
	
	for( i=0; i<N; i++ ) {
		if( !carg[i] ) 
			res[R2++] = i ;
	}
	
	while( R<R2 )  {
		sort( res+R, res+R2 ) ;
		i = R2 ;
		for( ; R<i; R++ ) {
			for( it=sig[res[R]].begin();  it!=sig[res[R]].end();  it++  )   {
				carg[*it] -- ;
				if( !carg[*it]  )
					res[R2++] = *it ;
			}
		}
	}
	
	if( R2 == N  )  {
		for( i=0; i<N; i++ )
			printf("%d\n", res[i]+1 ) ;
	}
	else {
		printf("IMPOSSIBLE\n" ) ;
	}
	
	return 0 ;
}
