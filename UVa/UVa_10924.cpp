#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>
using namespace std ;

bool comp[1100] ;

void criba() {
    int N = 1100 ;
    for( int i=2; i*i<N; i++ )
	if( !comp[i] )
	    for( int j=i*i; j<N; j+=i )
		comp[j] = 1 ;
}

int main() {
    char tmp[5005] ;
    char val[305] ;
    int N=0, tot ;

    criba() ;

    for( int i=0; i<26; i++ ) {
	val[i+'a'] = i+1 ;
	val[i+'A'] = i+27 ;
    }

    while( gets(tmp) ) {
	N = strlen(tmp) ;
	tot = 0 ;
	for( int i=0; i<N; i++ )
	    tot += val[tmp[i]] ;
	printf("It is %sa prime word.\n", comp[tot]? "not ":"" ) ;
    }
    
    return 0 ;
}

