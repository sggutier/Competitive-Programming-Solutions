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
#include <list>
#include <stack>
using namespace std ;

char mrk[300] ;

int main() {
	int N ;
	char S[1000] ;
	char ult = '|' ;
	int tip[] = { 0, 0 } ;

	scanf("%s", S ) ;
	N = strlen(S) ;

	mrk['A'] = 1 ;
	mrk['D'] = 1 ;
	mrk['E'] = 1 ;
	mrk['C'] = 2 ;
	mrk['F'] = 2 ;
	mrk['G'] = 2 ;

	for( int i=0; i<N; i++ ) {
		if( ult=='|' && mrk[S[i]]>0 )
			tip[ mrk[S[i]]-1 ] ++ ;
		ult = S[i] ;
	}

	if( tip[0]!=tip[1] )
		printf("%s\n", tip[0]>tip[1]? "A-mol":"C-dur" ) ;
	else
		printf("%s\n", mrk[ult]==1? "A-mol":"C-dur" ) ;

	return 0 ;
}


