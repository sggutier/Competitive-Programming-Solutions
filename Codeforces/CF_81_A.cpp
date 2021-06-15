#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <list>
using namespace std; 
#define lim 200005

int main() {
	int N ;
	char S[lim] ;
	list <char> L ;
	list <char> :: iterator it, it2 ;
	
	scanf("%s",S ) ;
	N = strlen(S) ;
	L.push_back( 'A' ) ;
	for( int i=0; i<N; i++ ) 
		L.push_back( S[i] ) ;
	L.push_back( 'B' ) ;
	
	for( it=L.begin(), it2=it, it2++;  it2!=L.end();  it++, it2++  )  {
		while( (*it)==(*it2)  )  {
			it2 = L.erase(it2) ;
			it = L.erase(it) ;
			it -- ;
		}
	}
	
	for( it=L.begin();  it!=L.end();  it++  )  
		if(  (*it)>='a' && (*it)<='z' )
			printf("%c",*it) ;
	cout << endl ;
	
	return 0 ;
}
