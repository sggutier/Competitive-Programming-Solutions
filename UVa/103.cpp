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

struct bx {
    int N, id ;
    vector <int> nums ;
    bx() {
    }
    void lee(int K, int _id) {
	N = K ;
	id = _id ;
	nums = vector<int> (N) ;
	for( int i=0; i<K; i++ )
	    scanf("%d", &nums[i] ) ;
	sort( nums.begin(), nums.end() ) ;
    }
};

bool operator<( bx A, bx B ) {
    int W = A.N ;
    for( int i=0; i<W; i++ ) {
	if( A.nums[i]!=B.nums[i] )
	    return A.nums[i] < B.nums[i] ;
    }
    return 0 ;
}

bool tMen( bx A, bx B ) {
    int W = A.N ;
    for( int i=0; i<W; i++ ) {
	if( A.nums[i]>=B.nums[i] )
	    return 0 ;
    }
    return 1 ;
}

int N, K ;
bx cajas[lim] ;
int dp[lim], ant[lim] ;

void caso() {
    int res = 0, pRes ;
    
    for( int i=0; i<N; i++ )
	cajas[i].lee(K, i) ;
    sort( cajas, cajas+N ) ;

    for( int i=N-1; i>=0; i-- ) {
	dp[i] = 0 ;
	ant[i] = N ;
	for( int j=i+1; j<N; j++ ) {
	    if(  tMen(cajas[i],cajas[j])  and dp[i]<dp[j] ) {
		dp[i] = dp[j] ;
		ant[i] = j ;
	    }
	}
	dp[i] ++ ;
	if( dp[i]>res ) {
	    res = dp[i] ;
	    pRes = i ;
	}
    }

    bool fst = 1 ;
    printf("%d\n", res) ;
    while( pRes<N ) {
	if( !fst )
	    printf(" " ) ;
	fst = 0 ;
	printf("%d", cajas[pRes].id+1 ) ;
	pRes = ant[pRes] ;
    }
    printf("\n" ) ;
}

int main() {
    while( scanf("%d%d", &N, &K )!=EOF  )
	caso() ;
    
    return 0 ;
}
