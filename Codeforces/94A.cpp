#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <map>
using namespace std ;

int main() {
	string S, a ;
	map <string,int> M ;
	int i ;
	
	cin >> S ;
	for( i=0; i<10; i++ ) {
		cin >> a ;
		M[a] = i ;
	}
	
	for( i=0; i<80; i+=10 )
		cout << M[ S.substr( i, 10 ) ] ;
	cout << endl ;
	
	return 0 ;
}
