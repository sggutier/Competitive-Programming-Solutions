#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std ;
const int lim = 1500006 ;

bool comp[lim] ;

void criba() {
	for( int i=2; i*i<lim; i++ ) 
		if( !comp[i]  )
			for( int j=i*i; j<lim; j+=i ) 
				comp[j] = 1 ;
}

int main() {
	int N ;
	int ult = 0 ;

	scanf("%d", &N ) ;

	criba() ;

	for( int i=2, cnt=0; cnt<N; i++ ) {
		if( !comp[i] ) {
			cnt ++ ;
			printf("%d ", i ) ;
		}
	}
	printf("\n" ) ;


	return 0 ;
}

