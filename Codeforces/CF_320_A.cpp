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
	string S ;

	cin >> S ;

	for( int i=0; i<S.size(); i++ ) {
		if( S[i]!='1' ) {
			printf("NO\n" ) ;
			return 0 ;
		}
		if( i+1<S.size() && S[i+1]=='4' ) 
			i ++ ;
		if( i+1<S.size() && S[i+1]=='4' ) 
			i ++ ;
	}

	printf("YES\n") ;

	return 0 ;
}

