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
const int lim = 100005 ;

int arr[lim] ;

int main() {
	int N ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ )
		scanf("%d", &N ) ;

	for( int b=30; b>=0; b-- ) {
		int cnt=0, msk = (1LL<<(b+1))-1 ;
		for( int i=0; i<N; i++ ) {
			if( (1<<b) & arr[i] ) {
				msk &= arr[i] ;
				cnt ++ ;
			}
		}

		if( cnt>0 && (msk&(1<<b))  ) {
			printf("%d\n", cnt ) ;
			for( int i=0; i<N; i++ )
				if( (1<<b) & arr[i] )
					printf("%d ", arr[i] ) ;
			printf("\n" ) ;
		}

	}

	printf("-1\n" ) ;

	return 0 ;
}

