#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;
#define lim 1000

int W ;
string pil[lim] ;

void act() {
	string S, tmp ;
	int pos = 0, pos2 ;
	
	cin >> S ;
	if( S[0] == '/' ) {
		W = 0 ;
		pos ++ ;
	}
	
	while( pos<S.size()  ) {
		tmp = "" ;
		pos2 = pos ;
		while( pos<S.size() && S[pos]!='/' ) 
			pos ++ ;
		tmp = S.substr( pos2, pos-pos2 ) ;
		if( pos<S.size() && S[pos]=='/' )
			pos ++ ;
			
		if( tmp==".." )
			W -- ;
		else 
			pil[ W++ ] = tmp ;
	}
}

int main() {
	int N ;
	
	cin >> N ;
	for( int i=0; i<N; i++ ) {
		string tip ;
		cin >> tip ;
		if( tip=="pwd" ) {
			for( int j=0; j<W; j++ ) 
				cout << "/" << pil[j] ;
			cout << "/\n" ;
		}
		else {
			act() ;
		}
	}
	
	return 0 ;
}
