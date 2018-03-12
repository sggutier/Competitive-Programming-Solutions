#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <cstring>
#include <list>
using namespace std ;
const int lim = 300 ;

int main() {
	int res = 1 ;

	for( int i=3; i<lim; i+=2 ) {
		bool primo = 1 ;
		for( int j=2; j*j<=i; j++ ) 
			if( i%j==0 )
				primo = 0 ;
		if( !primo )
			res ++ ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}


