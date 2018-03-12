#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <stack>
using namespace std ;

int main() {
	freopen( "ladyin.txt", "r", stdin ) ;
	freopen( "ladyout.txt", "w", stdout ) ;

	int N ;
	int mL = (1<<30), mR = -mL ;

	scanf("%d", &N ) ;
	for( int i=0; i<N; i++ ) {
		int tmp ;
		scanf("%d", &tmp ) ;
		mL = min( mL, tmp ) ;
		mR = max( mR, tmp ) ;
	}

	printf("%d\n", mR-mL+1 ) ;

	return 0 ;
}

