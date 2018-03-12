#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <utility>
#include <cmath>
using namespace std ;
const int lim = 1000005 ;
#define f first
#define s second
typedef long long ll ;
typedef pair<int, int> par;

bool comp[lim] ;

void criba() {
    for( int i=2; i*i<lim; i++ )
	if( !comp[i] )
	    for( int j=i*i; j<lim; j+=i )
		comp[j] = 1 ;
}

int main() {
    int n ;

    cin >> n ;
    criba() ;

    for( int i=2; i<=n; i++ ) {
	if( comp[i] && comp[n-i] ) {
	    printf("%d %d\n", i, n-i ) ;
	    return 0 ;
	}
    }
    
    return 0 ;
}
