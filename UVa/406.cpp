#include <cstdio>
#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std ;
const int lim = 100005 ;

int P=0;
int primos[lim] ;
bool comp[lim] ;

void caso(int X, int Y ) ;
void criba() ;
    

int main() {
    int a, b ;

    criba() ;
    while( scanf("%d%d", &a,&b) != EOF )
	caso( a, b  ) ;
    
    return 0 ;
}

void criba() {
    for( int i=2; i*i<lim; i++ )
	if( !comp[i] ) 
	    for( int j=i*i; j<lim; j+=i )
		comp[j] = 1 ;
    for( int i=1; i<lim; i++ )
	if( !comp[i] ) 
	    primos[P++] = i ;
}

void caso(int N, int D ) {
    int K = 0 ;
    int mit, dst1, dst2 ;

    for( ; primos[K]<=N; K++ ) ;
    mit = K/2 ;

    printf("%d %d:", N, D ) ;
    dst1 = max( mit - D+K%2, 0 )  ;
    dst2 = min( K-1, mit + D- 1 ) ;

    for( int i=dst1; i<=dst2; i++ )
	printf(" %d", primos[i] ) ;
    printf("\n" ) ;
    printf("\n" ) ;
}
