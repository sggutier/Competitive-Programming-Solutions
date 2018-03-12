#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <list>
using namespace std ;
#define lim 50007

int main() {
	int N, M ;
	string S ;
	int carg[lim][2], cmb[lim][2] ;
	list <int> res ;
	int ini=0, fin=0 ;
	int i, pos ;
	list <int> iterator :: it ;
	int w = 0 ;
	
	cin >> S ;
	N = S.size() ;
	res.push_back(0) ;
	for( i=0, M=0; i<N; i++ ) {
		
		if( S[i] == '(' ) {
			if( fin<0 ) 
				continue ;
			ini ++, fin ++ ;
		}
		else if( S[i] == ')' ) {
			if( fin<0 ) 
				continue ;
			fin -- ;
			
			if( ini ) 
				ini -- ;
		}
		else {
			scanf("%d%d", &carg[M][0], &carg[M][1] ) ;
			if( fin<0 ) 
				continue ;
			cmb[M][0] = ini ;
			cmb[M][0] = fin ;
			
			fin ++ ;
			res.push_back( carg[M][0] ) ;
			
			if( ini ) {
				ini -- ;
				res.push_back( carg[M][1] ) ;
			}
			
			M ++ ;
		}
	}
	
	if( fin<0 ) {
		printf("-1\n" ) ;
		return 0 ;
	}
	for( i=
	
	return 0 ;
}
