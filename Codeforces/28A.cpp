#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <cstring>
using namespace std ;
#define limN 505
#define limD 40005

int main() {
	int N, R ;
	int x[limN], y[limN] ;
	list <int> len[limD] ;
	int rep[limD] ;
	int i, j ;
	
	scanf("%d%d", &N, &R ) ;
	for( i=0; i<N; i++ ) {
		scanf("%d%d", &x[i], &y[i] ) ;
	}
	for( i=0; i<R; i++ ) {
		scanf("%d", &j ) ;
		if( j<limD )
			len[j].push_back(i) ;
	}
	
	for( i=0; i<N; i++ ) {
		if( x[i] == x[(i+1)%N]  &&  x[i] == x[(i+2)%N]    )   {
			printf("NO\n" ) ;
			return 0 ;
		}
		if( y[i] == y[(i+1)%N]  &&  y[i] == y[(i+2)%N]    )   {
			printf("NO\n" ) ;
			return 0 ;
		}
	}
	
	memset( rep, 0, sizeof(rep)  )  ;
	for( i=0; i<N; i+=2  )  {
		j  = abs(x[i      ]-x[(i+1)%N]) ;
		j += abs(x[(i+1)%N]-x[(i+2)%N]) ;
		j += abs(y[i      ]-y[(i+1)%N]) ;
		j += abs(y[(i+1)%N]-y[(i+2)%N]) ;
		rep[j] ++ ;
	}
	for( i=0; i<limD &&  rep[i]<=len[i].size(); i++ )  ;
	if( i==limD ) {
		printf("YES\n" ) ;
		for( i=0; i<N; i++ )
			rep[i] = -2 ;
		for( i=0; i<N; i+=2  )  {
			j  = abs(x[i      ]-x[(i+1)%N]) ;
			j += abs(x[(i+1)%N]-x[(i+2)%N]) ;
			j += abs(y[i      ]-y[(i+1)%N]) ;
			j += abs(y[(i+1)%N]-y[(i+2)%N]) ;
			rep[i+1] = *len[j].begin() ;
			len[j].erase( len[j].begin() ) ;
		}
		for( i=0; i<N; i++ ) 
			printf("%d ", rep[i]+1 ) ;
		printf("\n" ) ;
		return 0 ;
	}
	
	memset( rep, 0, sizeof(rep)  )  ;
	for( i=1; i<N; i+=2  )  {
		j  = abs(x[i      ]-x[(i+1)%N]) ;
		j += abs(x[(i+1)%N]-x[(i+2)%N]) ;
		j += abs(y[i      ]-y[(i+1)%N]) ;
		j += abs(y[(i+1)%N]-y[(i+2)%N]) ;
		rep[j] ++ ;
	}
	for( i=0; i<limD &&  rep[i]<=len[i].size(); i++ )  ;
	if( i==limD ) {
		printf("YES\n" ) ;
		for( i=0; i<N; i++ )
			rep[i] = -2 ;
		for( i=1; i<N; i+=2  )  {
			j  = abs(x[i      ]-x[(i+1)%N]) ;
			j += abs(x[(i+1)%N]-x[(i+2)%N]) ;
			j += abs(y[i      ]-y[(i+1)%N]) ;
			j += abs(y[(i+1)%N]-y[(i+2)%N]) ;
			rep[(i+1)%N] = *len[j].begin() ;
			len[j].erase( len[j].begin() ) ;
		}
		for( i=0; i<N; i++ ) 
			printf("%d ", rep[i]+1 ) ;
		printf("\n" ) ;
		return 0 ;
	}
	
	printf("NO\n" ) ;
	
	return 0 ;
}
