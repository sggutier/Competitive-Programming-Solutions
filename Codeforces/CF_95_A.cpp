#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std ;
#define lim 100005

int main() {
	int N ;
	string dic[lim] ;
	string org, cp, res ;
	string L ;
	string tmp ;
	int i, j, k ;
	char a, b ;
	
	
	cin >> N ;
	for( i=0; i<N; i++ )
		cin >> dic[i] ;
	cin >> org ;
	cin >> L ;
	
	for( i=0; i<N; i++ ) {
		for( j=0; j<dic[i].size(); j++ ) {
			if( dic[i][j] >= 'A' && dic[i][j] <='Z' ) 
				dic[i][j] = dic[i][j] -'A' + 'a' ;
		}
	}
	cp  = org ;
	if( L[0] >= 'A' && L[0] <='Z' ) 
		a = L[0] -'A' + 'a' ;
	else
		a = L[0] ;
	for( i=0; i<cp.size(); i++ ) {
		if( cp[i] >= 'A' && cp[i] <='Z' ) 
			cp[i] = cp[i] -'A' + 'a' ;
	}
	res = cp ;
	if( a=='a' )
		b = 'b' ;
	else
		b = 'a' ;
	
	for( i=0; i<cp.size(); i++ ) {
		for( j=0; j+i<=cp.size(); j++ ) {
			tmp = cp.substr( i, j ) ;
			for( k=0; k<N && tmp!=dic[k]; k++ ) ;
			if( k==N ) 
				continue ;
			for( k=0; k<j; k++ ) {
				if( cp[i+k] == a )
					res[i+k] = b ;
				else
					res[i+k] = a ;
			}
		}
	}
	for( i=0; i<res.size(); i++ ) {
		if( org[i] >= 'A' && org[i] <='Z' ) {
			if( res[i] >= 'a' && res[i] <='z' ) 
				res[i] = res[i]-'a'+'A' ;
		}
	}
	cout << res << endl ;
	
	return 0 ;
}
