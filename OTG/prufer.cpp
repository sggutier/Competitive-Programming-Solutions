#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std ;
#define lim 100000

int N ;
int arr[lim] ;
int rep[lim] ;
priority_queue <int>  Q ;
vector <int>  V[lim]  ;


int main() {
	int i, j, w ;
	
	scanf("%d",&N ) ;
	for( i=0; i+2<N; i++ ) {
		scanf("%d",&arr[i] ) ;
		arr[i] -- ;
		rep[ arr[i] ] ++ ;
	}
	
	
	for( i=0; i<N; i++ ) {
		if( !rep[i] ) {
			Q.push( -i ) ;
		}
	}
			
	for( i=0; i+2<N; i++ ) {
		w = -Q.top() ;
		Q.pop() ;
		V[ arr[i] ].push_back(w) ;
		V[ w ].push_back(arr[i]) ;
		
		rep[arr[i]] -- ;
		if( !rep[arr[i]]  )
			Q.push(  -arr[i]   ) ;
	}
	
	i = -Q.top() ;
	Q.pop() ;
	j = -Q.top() ;
	Q.pop() ;	
	V[ i ].push_back(j) ;
	V[ j ].push_back(i) ;
	
	for( i=0; i<N; i++ )
		sort(  V[i].begin(),  V[i].end()  )  ;
		
	for( i=0; i<N; i++ ) {
		for( j=0; j<V[i].size();  j++ ) {
			if( j )
				printf(" ");
			printf("%d",V[i][j]+1 ) ;
		}
		printf("\n");
	}
	
	return 0 ;
}
