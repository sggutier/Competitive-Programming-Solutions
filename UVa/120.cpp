#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std ;

int N ;
int arr[500] ;

void ordena() {
    for( int i=N-1; i; i-- ) {
	int cmb = i ;
	for( int j=0; j<i; j++ ) {
	    if( arr[j]>arr[cmb] )
		cmb = j ;
	}
	if( cmb==i )
	    continue ;
	if( cmb ) {
	    cout << N-cmb << " " ;
	    reverse( arr, arr+cmb+1 ) ;
	}
	cout << N-i << " " ;
	reverse( arr, arr+i+1 ) ;
    }
}

int main() {
    string ren ;

    while( getline(cin,ren) ) {
	cout << ren << endl ;
	ren += " " ;
	stringstream ss(ren) ;
	string tmp ;
	N = 0 ;
	while( getline(ss,tmp,' ') ) {
	    sscanf( tmp.c_str(), "%d", &arr[N++] ) ;
	}
	ordena() ;
	cout << 0 << endl ;
    }
    
    return 0 ;
}
