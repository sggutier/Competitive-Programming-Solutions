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

int ult( vector <int> sig, vector <int> ant, int N, int K ) {
    int pos = 0 ;
    while( N>1 ) {
	sig[ant[pos]] = sig[pos] ;
	ant[sig[pos]] = ant[pos] ;
	N -- ;
	for( int i=K; i; i--, pos=sig[pos] ) ;
    }
    return pos ;
}

int caso(int N) {
    vector <int> sig(N,0), ant(N,0) ;
    for( int i=0; i<N; i++ ) {
	sig[i] = (i+1)%N ;
	ant[i] = (i-1+N)%N ;
    }
    for( int i=1; i<N; i++ )
	if( ult(sig,ant,N,i)==12 )
	    return i ;
    return -1 ;
}

int main() {
    int tmp ;

    while( scanf("%d",&tmp)!=EOF && tmp )
	printf("%d\n", caso(tmp) ) ;
    
    return 0 ;
}
