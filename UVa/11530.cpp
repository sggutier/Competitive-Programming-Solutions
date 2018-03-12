#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std ;
#define parI pair <int,int>
#define p1 first
#define p2 second
#define mkp make_pair
const int inf = 1e9 ;
const int lim = 300 ;

int cnt[8] ;
int pBtns[lim] ;
char S[lim] ;

void caso() {
    fgets( S, lim, stdin ) ;
    int N = strlen(S), res=0 ;

    for( int i=0; i<N; i++  )
	res += pBtns[ tolower(S[i]) ] ;

    printf("%d\n", res ) ;
}


int main() {
    for( int i=0; i<8; i++ )
	cnt[i] = 3 ;
    cnt[7] = cnt[5] = 4 ;
    for( int pos='a', i=0; i<9; i++ ) {
	for( int j=0; j<cnt[i]; j++, pos++ )
	    pBtns[pos] = j+1 ;
    }
    pBtns[' '] = 1 ;

    int T ;
    fgets( S, lim, stdin ) ;
    sscanf( S, "%d", &T ) ;
    for( int i=0; i<T; i++ ) {
	printf("Case #%d: ", i+1 ) ;
	caso() ;
    }
    
    return 0 ;
}
