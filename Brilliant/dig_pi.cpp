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
const int lim = 1000007 ;

int N = 0 ;
char arr[lim] ;

int main() {
	freopen( "cs_pi.txt", "r", stdin ) ;

	char c ;
	int res = 0 ;

	while( scanf("%c", &c ) != EOF ) {
		if( c>='0' && c<='9' ) 
			arr[N++] = c ;
	}

	for( int i=0, ult=-1, tam=0; i<N; i++ ) {
		if( arr[i]!=ult ) {
			ult = arr[i] ;
			tam = 0 ;
		}
		tam ++ ;
		res = max( res, tam ) ;
	}

	printf("%d\n", res ) ;

	return 0 ;
}


