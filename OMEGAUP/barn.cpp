#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std ;
#define lim 150005

int main() {
	int maxUsd, O ;
	int oc[lim] ;
	int usd=1, res=0 ;
	int i, j ;
	priority_queue <int> Q ;
	
	scanf("%d", &maxUsd ) ;
	scanf("%d", &O ) ;
	scanf("%d", &O ) ;
	for( int i=0; i<O; i++ )
		scanf("%d", &oc[i] ) ;
		
	sort( oc, oc+O ) ;
	for( i=1, res++; i<O && oc[i]==oc[i-1]+1; i++, res++ ) ;
	for( ; i<O; i=j, usd++ ) {
		Q.push( -oc[i]+oc[i-1]+1 ) ;
		for( j=i+1, res++; j<O && oc[j]==oc[j-1]+1; j++, res++ ) ;
	}
	
	for( ; usd>maxUsd; usd-- ) {
		res -= Q.top() ;
		Q.pop() ;
	}
	
	printf("%d\n", res ) ;
	
	return 0 ;
}

