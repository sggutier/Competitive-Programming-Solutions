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
const int lim = 3005 ;
const int mod = 1000000007LL ;

int trian[lim][lim] ;

void caso() ;
void precalc() ;

int main() {
    int T ;

    precalc() ;
    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ )
	caso() ;
    
    return 0 ;
}

void caso() {
    int bt=1 ;
    int N ;

    scanf("%d",&N) ;
    
    while( bt-1<=N ) {
	bt *= 2 ;
    }
    bt /= 2 ;
    //cout << N << " " << bt << endl;

    printf("%d\n", (trian[bt][N-(bt-1)]+(mod-1))%mod  ) ;
}

void precalc() {
    for( int i=0; i<lim; i++ ) {
	trian[i][0] = trian[i][i] = 1LL ;
	for( int j=1; j<i; j++ ) {
	    trian[i][j] = (trian[i-1][j] + trian[i-1][j-1])%mod ;
	}
    }
}
