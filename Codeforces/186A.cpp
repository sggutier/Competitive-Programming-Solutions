#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int rep[26] ;

int main() {
	string S, S2 ;
	int dif = 0 ;
	int D[2] ;
	
	cin >> S ;
	for( int i=0; i<S.size(); i++ ) 
		rep[ S[i]-'a' ] ++ ;
	cin >> S2 ;
	for( int i=0; i<S2.size(); i++ ) 
		rep[ S2[i]-'a' ] -- ;
		
	for( int i=0; i<26; i++ ) {
		if( rep[i] ) {
			printf("NO\n" ) ;
			return 0 ;
		}
	}
	
	for( int i=0; i<S.size(); i++ ) {
		if( S[i]==S2[i] )
			continue ;
		if( dif==2 ) {
			printf("NO\n" ) ;
			return 0 ;
		}
		D[ dif++ ] = i ;
	}
	
	if( dif==1 || ( dif==2 && S[D[0]] != S2[D[1]] && S2[D[0]] != S[D[1]]  ) ) {
		printf("NO\n" ) ;
		return 0 ;
	}
	
	printf("YES\n" ) ;
	
	return 0 ;
}
