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
const int lim = 100005 ;

char S[lim] ;

void printa( int sum ) {
	if( sum==0 )
		printf("1\n" ) ;
	else if( sum==1 )
		printf("7\n" ) ;
	else 
		printf("4\n" ) ;
}

int main() {
	int sum = 0 ;
	char tmp, ult='x' ;

	while( scanf("%c", &tmp ) != EOF ) {
		if( tmp==10 && ult!=10 ) {
			printa(sum) ;
			sum = 0 ;
		}
		else if( tmp!=32 )
			sum = (sum+tmp-'0')%3 ;
		ult = tmp ;
	}

	return 0 ;
}

