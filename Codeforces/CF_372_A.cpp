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
const int lim = 500005 ;

int N ;
int kang[lim] ;

int main() {
	int a, b ;
	int res ;

	scanf("%d", &N );
	for( int i=0; i<N; i++ ) 
		scanf("%d", &kang[i] ) ;
	res = N ;

	sort( kang, kang+N ) ;

	for( b=N-1, a=(N-1)/2; a>=0; a-- ) {
		while( b>a && kang[b]==-1 ) {
			b -- ;
		}
		if( a!=b && kang[b]>=kang[a]*2 )  {
			kang[a] = -1 ;
			b -- ;
			res -- ;
		}
	}

	printf("%d\n", res ) ;

	return 0 ;
}


