#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int main() {
	int N, a, b ;
	
	cin >> N >> a >> b ;
	N /= 2 ;
	if( (a==N || a==N+1) && (b==N || b==N+1)   )   
		cout << "NO" << endl ;
	else
		cout << "YES" << endl ;
	
	return 0 ;
}
