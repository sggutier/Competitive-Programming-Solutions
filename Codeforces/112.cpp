#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std ;

int main() {
	string a, b ;
	
	cin >> a >> b ;
	for( int i=0; i<a.size(); i++  )  
		if( a[i] >= 'A' && a[i] <='Z'   )
			a[i] = a[i]-'A'+'a' ;
	for( int i=0; i<b.size(); i++  )  
		if( b[i] >= 'A' && b[i] <='Z'   )
			b[i] = b[i]-'A'+'a' ;
	if( a<b )
		cout << -1 << endl ;
	else if( a>b )
		cout << 1 << endl ;
	else
		cout << 0 << endl ;
	
	return 0 ;
}
