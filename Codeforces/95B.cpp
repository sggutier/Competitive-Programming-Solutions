#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std ;

string S ;
string res ;
int N ;

bool sePuede( int pos, int carg, bool may ) {
	if(  N-pos-abs(carg)<0  ||   (N-pos-abs(carg))%2   )
		return 0 ;
	if( pos == N ) {
		return carg==0 ;
	}
	
	if( may ) {
		int a ;
		a = (N-pos-abs(carg)) / 2 ;
		if( carg>=0 ) 
			a += carg ;
		for(  ; a; pos++, a-- ) 
			res[pos] = '4' ;
		for( ; pos<N; pos++ ) 
			res[pos] = '7' ;
		return 1 ;
	}
	
	if( S[pos] < '4' ) {
		if(   sePuede( pos+1, carg-1, 1 )     ) {
			res[pos] = '4' ;
			return 1 ;
		}
		if(  sePuede( pos+1, carg+1, 1 )   ) {
			res[pos] = '7' ;
			return 1 ;
		}
		return 0 ;
	}
	else if( S[pos] == '4' ) {
		if(   sePuede( pos+1, carg-1, 0 )     ) {
			return 1 ;
		}
		if(  sePuede( pos+1, carg+1, 1 )   ) {
			res[pos] = '7' ;
			return 1 ;
		}
		return 0 ;
	}
	else if( S[pos] < '7' ) {
		if(  sePuede( pos+1, carg+1, 1 )   ) {
			res[pos] = '7' ;
			return 1 ;
		}
		return 0 ;
	}
	else if( S[pos]=='7' ) {
		return  sePuede( pos+1, carg+1, 0 )   ;
	}
	return 0 ;
}

int main() {
	cin >> S ;
	
	N = S.size() ;
	
	res = S ;
	if( sePuede( 0, 0, 0 )   )  {
		cout << res << endl ;
	}
	else {
		if( N%2 ) 
			N ++ ;
		else
			N += 2 ;
		N /= 2 ;
		for( int i=0; i<N; i++ ) 
			printf("4" ) ;
		for( int i=0; i<N; i++ ) 
			printf("7" ) ;
		cout << endl ;
	}
	
	return 0 ;
}

