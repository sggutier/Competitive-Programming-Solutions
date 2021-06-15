#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std ;

int main() {
	int N ;
	string res[5] = {   "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"   }  ;

	scanf("%d",&N ) ;
	N -- ;
	
	while( N>=5 ) {
		N -= 5 ;
		N /= 2 ;
	}
	
	cout << res[N] << endl ;
	
	return 0 ;
}
