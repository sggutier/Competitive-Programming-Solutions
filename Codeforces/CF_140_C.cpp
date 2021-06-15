#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std ;
#define lim 100005
#define f first
#define s second
typedef pair<int,int> par;

int N, R=0 ;
int arr[lim], res[lim][3] ;

priority_queue <par> Q ;

int main() {
	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &arr[i] ) ;
		
	sort( arr, arr+N ) ;
	for( int i=0; i<N; i++ ) {
		int j = i+1; 
		for( ; j<N && arr[j]==arr[j-1]; j++ ) ;
		Q.push( par( j-i, arr[j-1]  )   );
		i = j-1 ;
	}
	
	while( Q.size()>=3 ) {
		par a, b, c ;
		
		a = Q.top(), Q.pop() ;
		b = Q.top(), Q.pop() ;
		c = Q.top(), Q.pop() ;
		a.f -- ;
		b.f -- ;
		c.f -- ;
		res[R][0] = a.s ;
		res[R][1] = b.s ;
		res[R][2] = c.s ;
		R ++ ;
		
		if( a.f ) Q.push(a) ;
		if( b.f ) Q.push(b) ;
		if( c.f ) Q.push(c) ;
	}
	
	printf("%d\n", R ) ;
	for( int i=0; i<R; i++ ) {
		sort( res[i], res[i]+3 ) ;
		for( int j=2; j>=0; j-- )
			printf("%d ", res[i][j] ) ;
		printf("\n" ) ;
	}
	
	return 0 ;
}


