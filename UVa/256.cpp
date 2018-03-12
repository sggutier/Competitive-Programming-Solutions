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

vector <int> res[4] ;

void caso( int N, int pot, vector <int> &ans ) {
    for( int i=0; i<pot; i++ ) {
	int tmp = i*i ;
	if( tmp/pot + tmp%pot == i )
	    ans.push_back(tmp) ;
    }
}

int main() {
    int N ;
    
    for( int i=0, pot=10; i<4; i++, pot*=10 )
	caso( i+1, pot, res[i] ) ;

    char ans[] = "%02d\n" ;
    while( scanf("%d",&N)!=EOF ) {
	ans[2] = N+'0' ;
	N = N/2-1 ;
	for( int i=0; i<res[N].size(); i++ ) {
	    printf( ans, res[N][i] ) ;
	}
    }
    
    return 0 ;
}
