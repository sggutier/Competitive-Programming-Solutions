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

int main() {
	char S[100], inst[100] ;
	int X, Y, a=0, b=0 ;

	scanf("%s", inst ) ;
	scanf("%s", S ) ;
	X = strlen(S) ;
	Y = strlen(inst) ;

	while( a<X && b<Y ) {
		if( S[a]==inst[b] )
			b ++ ;
		a ++ ;
	}

	printf("%d\n", b+1 ) ;
	
	return 0 ;
}

