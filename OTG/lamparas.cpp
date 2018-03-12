#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
using namespace std ;

int main() {
	int N, C ;
	list <int> enc, ap ;
	int camb[] = { 1, 2, 2, 3 } ;
	int ini[] = { 0, 0, 1, 0 } ;
	int b, i, j, w ;
	list <int> :: iterator it ;
	char S[10005] ;
	string res[1<<4] ;
	int nRes = 0 ;
	
	scanf("%d%d", &N, &C ) ;
	do {
		scanf("%d", &w ) ;
		if( w!=-1 )	
			enc.push_back( w-1 ) ;
	} while( w!=-1 ) ;
	do {
		scanf("%d", &w ) ;
		if( w!=-1 )	
			ap.push_back( w-1 ) ;
	} while( w!=-1 ) ;
	
	for( b=0; b<(1<<4); b++ ) {
		w = 0 ;
		for( i=0; i<4; i++ )
			if( (1<<i) & b )
				w ++ ;
		if( w>C || (C-w)%2 )
			continue ;
			
		for( i=0; i<N; i++ )
			S[i] = '1' ;
		for( w=0; w<4; w++ ) {
			if( ! ( (1<<w) & b )    )
				continue ;
			for( i=ini[w]; i<N; i+=camb[w]  ) 
				S[i] = (   ( S[i]-'0' ) ^ 1 ) + '0'  ;
		}
		
		for( it=enc.begin(); it!=enc.end(); it++ ) {
			if( S[*it] == '0' )
				break ;
		}
		if( it!=enc.end()  ) 
			continue ;
		for( it=ap.begin(); it!=ap.end(); it++ ) {
			if( S[*it] == '1' )
				break ;
		}
		if( it!=ap.end()  ) 
			continue ;
			
		res[nRes++] = S ;
	}
	
	sort( res, res+nRes ) ;
	printf("%d\n", nRes ) ;
	for( i=0; i<nRes; i++ ) {
		cout << res[i] << endl ;
	}
	
	return 0 ;
}
